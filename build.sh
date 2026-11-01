#!/bin/sh
set -e
cd "$(dirname "$0")"
patch=${1:-ble_hid}
have=${2:-}
version=zero2_v1.08
program=firmware/decrypted/$version.s1.bin

missing=
for tool in cc curl; do
    command -v "$tool" > /dev/null 2>&1 || missing="$missing $tool"
done
if [ -n "$missing" ]; then
    echo "build.sh: not installed:$missing" >&2
    echo "  Debian, Ubuntu:  sudo apt install build-essential curl" >&2
    echo "  Fedora:          sudo dnf install gcc make curl" >&2
    echo "  Arch:            sudo pacman -S base-devel curl" >&2
    exit 1
fi

echo "== the tool"
mkdir -p build
cc -O2 -o build/zero2 tools/zero2.c -lm

if [ -n "$have" ]; then
    echo "== firmware file"
    mkdir -p firmware/official firmware/decrypted
    cp "$have" firmware/official/$version.dat
    ./build/zero2 decrypt firmware/official/$version.dat -s 1 -o "$program" 2>&1 | tail -1
elif [ -f "$program" ]; then
    echo "== 8BitDo's firmware is already here"
else
    echo "== 8BitDo's firmware, from their update server"
    mkdir -p firmware/official firmware/decrypted
    sh tools/fetch_firmware.sh firmware/official
    sh tools/decrypt.sh
fi
[ -f "$program" ] || {
    echo "build.sh: $program did not arrive. 8BitDo's server offers whatever versions it likes;" >&2
    echo "this build patches v1.08, so if that is no longer offered, pass a .dat you have:" >&2
    echo "  ./build.sh $patch /path/to/zero2_v1.08.dat" >&2
    exit 1; }

arm=yes
for tool in arm-none-eabi-as arm-none-eabi-ld arm-none-eabi-objcopy arm-none-eabi-nm; do
    command -v "$tool" > /dev/null 2>&1 || arm=no
done
if [ "$arm" = yes ] && [ -f "patches/$patch.s" ]; then
    echo "== the patch, from patches/$patch.s"
    cc -O2 -o build/genble tools/genble.c
    ./build/genble "$patch"
elif [ -f "patches/$patch.txt" ]; then
    echo "== the patch"
else
    echo "build.sh: no patches/$patch.txt, and no ARM toolchain to build it from" \
         "patches/$patch.s" >&2
    exit 1
fi
./build/zero2 patch "patches/$patch.txt"

echo
echo "flash this:   out/$patch/$patch.dat"
echo "it should be: out/$patch/$patch.plain"
echo
echo "Hold L + R + START, then connect the gamepad using USB, find the device and note it:"
echo "  grep -l 3208 /sys/class/hidraw/*/device/uevent"
echo "  sudo ./build/zero2 flash /dev/hidrawN out/$patch/$patch.dat --plain out/$patch/$patch.plain"
echo "If ends with \"verify: OK\" then all went OK."
