PATCH = ble_hid
VERSION = zero2_v1.08
IMAGE = out/$(PATCH)/$(PATCH).plain
PROGRAM = firmware/decrypted/$(VERSION).s1.bin
DUMP = firmware/dumped/$(VERSION).dump.bin
PROGRAM_ADDR = 0x01018000
PROGRAM_SIZE = 0x11E00                  # 73216 bytes, the program as 8BitDo ships it
IMAGE_SIZE = 0x14000                    # with the flash the patch adds after it

HIDRAW ?= $(shell for u in /sys/class/hidraw/*/device/uevent; do grep -q 3208 "$$u" 2>/dev/null && \
	echo /dev/$$(basename $$(dirname $$(dirname $$u))); done | head -1)

CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
LD = arm-none-eabi-ld
OBJCOPY = arm-none-eabi-objcopy
HOSTCC = cc

CFLAGS = -mcpu=cortex-m0 -mthumb -Os -ffreestanding -fno-builtin -fno-common -fomit-frame-pointer \
         -fno-strict-aliasing -fno-tree-loop-distribute-patterns -fno-inline -fno-ipa-ra -fno-ipa-icf \
         -ffunction-sections -w -Iinclude

OBJ = $(patsubst src/%.c,build/%.o,$(wildcard src/*.c)) build/blob.o
TOOLS = build/zero2 build/genble

all: build/zero2.bin

tools: $(TOOLS)

build/zero2: tools/zero2.c | build
	$(HOSTCC) -O2 -o $@ $< -lm

build/genble: tools/genble.c | build
	$(HOSTCC) -O2 -o $@ $<

firmware: $(PROGRAM)

$(PROGRAM): build/zero2
	mkdir -p firmware/official firmware/decrypted
	sh tools/fetch_firmware.sh firmware/official
	sh tools/decrypt.sh

patches/$(PATCH).txt: patches/$(PATCH).s build/genble $(PROGRAM)
	./build/genble $(PATCH)

patch: $(IMAGE)

$(IMAGE): patches/$(PATCH).txt build/zero2 $(PROGRAM)
	./build/zero2 patch patches/$(PATCH).txt

blob/blob.bin: blob/blob.S $(IMAGE)
	sh tools/gen_blob.sh $(IMAGE)

build/%.s: src/%.c include/zero2.h | build
	$(CC) $(CFLAGS) -S -o $@ $<
	sed -i 's/^\t\.align\t2$$/\t.balign 4, 0/' $@

build/%.o: build/%.s
	$(AS) -mcpu=cortex-m0 -o $@ $<

build/blob.o: blob/blob.S blob/blob.bin | build
	$(AS) -mcpu=cortex-m0 -Iblob -o $@ $<

build/zero2.elf: $(OBJ) link.ld
	$(LD) -T link.ld -o $@ $(OBJ)

build/zero2.bin: build/zero2.elf
	$(OBJCOPY) -O binary $< $@

check: build/zero2.bin $(IMAGE)
	cmp build/zero2.bin $(IMAGE)
	@echo "build/zero2.bin is $(IMAGE), byte for byte"

device:
	@test -n "$(HIDRAW)" || { echo "no pad in boot mode: hold L + R + START while plugging in USB,"; \
		echo "or pass the node yourself with HIDRAW=/dev/hidrawN"; exit 1; }
	@echo "pad at $(HIDRAW)"

probe: build/zero2 device
	./build/zero2 probe $(HIDRAW)

dump: build/zero2 device
	mkdir -p firmware/dumped
	./build/zero2 read $(HIDRAW) $(PROGRAM_ADDR) $(IMAGE_SIZE) $(DUMP)

verify: $(DUMP) $(IMAGE)
	cmp $(DUMP) $(IMAGE)
	@echo "the pad is running $(IMAGE), byte for byte"

base-from-dump: $(DUMP) build/zero2
	mkdir -p firmware/decrypted
	dd if=$(DUMP) of=$(PROGRAM) bs=1 count=$$(($(PROGRAM_SIZE))) status=none
	@echo "$(PROGRAM): the first $(PROGRAM_SIZE) bytes of $(DUMP)"

flash: build/zero2 device $(IMAGE)
	./build/zero2 flash $(HIDRAW) out/$(PATCH)/$(PATCH).dat --plain $(IMAGE)

build:
	mkdir -p build

clean:
	rm -rf build blob/blob.bin

distclean: clean
	rm -rf out firmware patches/$(PATCH).txt

.PHONY: all tools firmware patch check device probe dump verify base-from-dump flash clean distclean
.SECONDARY:
