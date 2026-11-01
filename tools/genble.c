#include <errno.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#define BASE 0x01018000u
#define SIZE 0x14000u
#define CODE 0x0102A000u
#define SDP_AT 0x0102B000u
#define GAMEPAD 0x03C4
#define MODES 5
static void die(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    fputs("genble: ", stderr);
    vfprintf(stderr, fmt, ap);
    fputc('\n', stderr);
    va_end(ap);
    exit(1);
}
static const uint32_t RECORD[MODES] = { 0x2035C, 0x1028953, 0x1028C2C, 0x1028745, 0x1028F07 };
static const uint32_t SDP_LEN[MODES] = { 553, 729, 731, 526, 508 };
static const uint32_t SDP_PTR[MODES] = { 0x0101FDE0, 0x0101FE8C, 0x0101FEE4, 0x0101FE38, 0x0101FF34 };
static const uint8_t CLASSIC_BATTERY[MODES] = { 0, 0, 0x0A, 0x0A, 0x0A };
static const uint8_t MAIN_REPORT[MODES] = { 0x30, 0x01, 0x01, 0x03, 0x01 };
static const uint16_t MAIN_MTU[MODES] = { 200, 23, 23, 23, 23 };
static const uint16_t APPEARANCE[MODES] = { GAMEPAD, GAMEPAD, GAMEPAD, GAMEPAD, 0x03C1 };
static const char NAME[] = "Zero 2 BLE";
struct site { uint32_t at; const char *kind; };
static const struct site LENGTH_SITE[MODES][2] = {
    { { 0, NULL }, { 0, NULL } },
    { { 0, NULL }, { 0, NULL } },
    { { 0x0101FD3E, "adds" }, { 0x0101FD4C, "adds" } },
    { { 0x0101FCB2, "subs" }, { 0, NULL } },
    { { 0x0101FD88, "pair" }, { 0x0101FD96, "pair" } },
};
static uint8_t *IMG;
static size_t IMG_LEN;
static uint8_t RAM[0x78C];
static uint32_t PARAMS = 0x0102A400u;
static uint8_t *slurp(const char *path, size_t *len)
{
    FILE *f = fopen(path, "rb");
    if (!f)
        die("%s: %s", path, strerror(errno));
    fseek(f, 0, SEEK_END);
    long n = ftell(f);
    rewind(f);
    uint8_t *b = malloc((size_t)n + 1);
    if (!b || fread(b, 1, (size_t)n, f) != (size_t)n)
        die("%s: short read", path);
    b[n] = 0;
    fclose(f);
    *len = (size_t)n;
    return b;
}
static uint16_t be16(const uint8_t *b) { return b[0] << 8 | b[1]; }
static void unpack_ram(void)
{
    size_t out = 0, i = 0x0102984C - BASE;
    while (out < sizeof RAM) {
        uint8_t t = IMG[i++];
        unsigned cnt = t & 7, ln = t >> 4;
        if (!cnt)
            cnt = IMG[i++];
        if (!ln)
            ln = IMG[i++];
        for (unsigned k = 0; k + 1 < cnt; k++)
            RAM[out++] = IMG[i++];
        if (t & 8) {
            unsigned off = IMG[i++];
            for (unsigned k = 0; k < ln + 2u; k++, out++)
                RAM[out] = RAM[out - off];
        } else {
            for (unsigned k = 0; k < ln; k++)
                RAM[out++] = 0;
        }
    }
}
static const uint8_t *mem(uint32_t a)
{
    return a >= BASE ? IMG + (a - BASE) : RAM + (a - 0x20000);
}
static const uint8_t *find(const uint8_t *hay, size_t n, const uint8_t *needle, size_t m)
{
    for (size_t i = 0; i + m <= n; i++)
        if (!memcmp(hay + i, needle, m))
            return hay + i;
    return NULL;
}
struct bytes { uint8_t b[4096]; size_t n; };
static void put(struct bytes *o, const void *p, size_t n)
{
    if (o->n + n > sizeof o->b)
        die("descriptor is too long");
    memcpy(o->b + o->n, p, n);
    o->n += n;
}
static void put1(struct bytes *o, uint8_t v) { put(o, &v, 1); }
static struct bytes descriptor(int mode)
{
    const uint8_t *blob = mem(RECORD[mode]);
    const uint8_t pat[3] = { 0x09, 0x02, 0x06 }, tag[2] = { 0x08, 0x22 };
    const uint8_t *i = find(blob, 0x400, pat, 3);
    if (!i)
        die("mode %d: no HID descriptor attribute", mode);
    const uint8_t *j = find(i, 16, tag, 2);
    if (!j)
        die("mode %d: no descriptor after its attribute", mode);
    size_t n;
    const uint8_t *s;
    if (j[2] == 0x25) {
        n = j[3];
        s = j + 4;
    } else {
        n = be16(j + 3);
        s = j + 5;
    }
    struct bytes out = { { 0 }, 0 };
    put(&out, s, n);
    return out;
}
static size_t item_size(uint8_t head)
{
    size_t s = head & 3;
    return s == 3 ? 4 : s;
}
static const uint8_t GLOBALS[] = { 0x04, 0x14, 0x24, 0x34, 0x44, 0x54, 0x64, 0x74, 0x94 };
#define NGLOBALS (sizeof GLOBALS)
static int global_index(uint8_t tag)
{
    for (size_t i = 0; i < NGLOBALS; i++)
        if (GLOBALS[i] == tag)
            return (int)i;
    return -1;
}
static int is_local(uint8_t tag)
{
    static const uint8_t L[] = { 0x08, 0x18, 0x28, 0x38, 0x48, 0x58, 0x68, 0x78, 0x88, 0x98 };
    for (size_t i = 0; i < sizeof L; i++)
        if (L[i] == tag)
            return 1;
    return 0;
}
struct item { uint8_t b[5]; uint8_t n; };
struct level { struct item open, page; struct bytes pre; };
struct kept {
    struct level path[8];
    int depth;
    struct item want[NGLOBALS];
    struct bytes loc;
    struct item it;
};
static int same_item(const struct item *a, const struct item *b)
{
    return a->n == b->n && !memcmp(a->b, b->b, a->n);
}
static int same_level(const struct level *a, const struct level *b)
{
    return same_item(&a->open, &b->open) && same_item(&a->page, &b->page)
        && a->pre.n == b->pre.n && !memcmp(a->pre.b, b->pre.b, a->pre.n);
}
static struct bytes minimal(const struct bytes *desc, uint8_t keep)
{
    static struct kept kept[512];
    int nkept = 0;
    struct item want[NGLOBALS] = { { { 0 }, 0 } };
    struct bytes loc = { { 0 }, 0 };
    struct level path[8];
    int depth = 0, cur = -1;
    for (size_t i = 0; i < desc->n;) {
        size_t sz = item_size(desc->b[i]);
        struct item it = { { 0 }, (uint8_t)(1 + sz) };
        memcpy(it.b, desc->b + i, it.n);
        uint8_t tag = desc->b[i] & 0xFC;
        i += it.n;
        int g = global_index(tag);
        if (tag == 0x84) {
            cur = it.b[1];
        } else if (g >= 0) {
            want[g] = it;
        } else if (is_local(tag)) {
            put(&loc, it.b, it.n);
        } else if (tag == 0xA0) {
            if (depth == 8)
                die("collections nested too deep");
            path[depth].open = it;
            path[depth].page = want[global_index(0x04)];
            path[depth].pre = loc;
            depth++;
            loc.n = 0;
        } else if (tag == 0xC0) {
            if (depth)
                depth--;
            loc.n = 0;
        } else if (tag == 0x80 || tag == 0x90 || tag == 0xB0) {
            if (tag == 0x80 && cur == keep) {
                if (nkept == 512)
                    die("too many input items");
                struct kept *k = &kept[nkept++];
                k->depth = depth;
                memcpy(k->path, path, sizeof(struct level) * depth);
                memcpy(k->want, want, sizeof want);
                k->loc = loc;
                k->it = it;
            }
            loc.n = 0;
        }
    }
    struct bytes out = { { 0 }, 0 };
    struct item have[NGLOBALS] = { { { 0 }, 0 } };
    struct level open_path[8];
    int open_depth = 0, rid = 0;
    for (int e = 0; e < nkept; e++) {
        struct kept *k = &kept[e];
        int common = 0;
        while (common < open_depth && common < k->depth
               && same_level(&open_path[common], &k->path[common]))
            common++;
        for (int c = open_depth - common; c > 0; c--)
            put1(&out, 0xC0);
        for (int d = common; d < k->depth; d++) {
            struct level *l = &k->path[d];
            int pg = global_index(0x04);
            if (l->page.n && !same_item(&have[pg], &l->page)) {
                put(&out, l->page.b, l->page.n);
                have[pg] = l->page;
            }
            put(&out, l->pre.b, l->pre.n);
            put(&out, l->open.b, l->open.n);
        }
        memcpy(open_path, k->path, sizeof(struct level) * k->depth);
        open_depth = k->depth;
        if (!rid) {
            put1(&out, 0x85);
            put1(&out, keep);
            rid = 1;
        }
        for (size_t g = 0; g < NGLOBALS; g++)
            if (k->want[g].n && !same_item(&have[g], &k->want[g])) {
                put(&out, k->want[g].b, k->want[g].n);
                have[g] = k->want[g];
            }
        put(&out, k->loc.b, k->loc.n);
        put(&out, k->it.b, k->it.n);
    }
    for (int c = open_depth; c > 0; c--)
        put1(&out, 0xC0);
    return out;
}
static uint32_t item_value(const struct item *it)
{
    uint32_t v = 0;
    for (int i = it->n - 1; i >= 1; i--)
        v = v << 8 | it->b[i];
    return v;
}
static size_t report_bytes(const struct bytes *desc, uint8_t keep)
{
    uint32_t bits = 0, size = 0, count = 0;
    int cur = -1;
    for (size_t i = 0; i < desc->n;) {
        struct item it = { { 0 }, (uint8_t)(1 + item_size(desc->b[i])) };
        memcpy(it.b, desc->b + i, it.n);
        uint8_t tag = desc->b[i] & 0xFC;
        i += it.n;
        uint32_t v = item_value(&it);
        if (tag == 0x84)
            cur = (int)v;
        else if (tag == 0x74)
            size = v;
        else if (tag == 0x94)
            count = v;
        else if (tag == 0x80 && cur == keep)
            bits += size * count;
    }
    if (bits % 8)
        die("report is not whole bytes");
    return bits / 8;
}
static void check(const struct bytes *desc)
{
    int depth = 0;
    for (size_t i = 0; i < desc->n;) {
        uint8_t tag = desc->b[i] & 0xFC;
        i += 1 + item_size(desc->b[i]);
        if (tag == 0xA0)
            depth++;
        else if (tag == 0xC0 && --depth < 0)
            die("collection closed too often");
    }
    if (depth)
        die("collection left open");
}
static void sdp_elem(const uint8_t *b, size_t i, size_t *hs, size_t *n)
{
    uint8_t t = b[i];
    unsigned si = t & 7;
    if (si < 5) {
        static const size_t fixed[] = { 1, 2, 4, 8, 16 };
        *hs = 1;
        *n = (t >> 3) == 0 ? 0 : fixed[si];
        return;
    }
    size_t w = si == 5 ? 1 : si == 6 ? 2 : 4;
    *hs = 1 + w;
    size_t v = 0;
    for (size_t k = 0; k < w; k++)
        v = v << 8 | b[i + 1 + k];
    *n = v;
}
struct field { size_t off, width; };
static size_t descriptor_place(const uint8_t *blob, size_t len, struct field *fields, int *nf,
                               size_t *size)
{
    size_t hs, n;
    sdp_elem(blob, 13, &hs, &n);
    *nf = 0;
    fields[(*nf)++] = (struct field){ 14, hs - 1 };
    const uint8_t pat[3] = { 0x09, 0x02, 0x06 };
    const uint8_t *p = find(blob + 13, len - 13, pat, 3);
    if (!p)
        die("no HIDDescriptorList attribute");
    size_t i = (size_t)(p - blob) + 3;
    for (int k = 0; k < 2; k++) {
        sdp_elem(blob, i, &hs, &n);
        fields[(*nf)++] = (struct field){ i + 1, hs - 1 };
        i += hs;
    }
    if (blob[i] != 0x08 || blob[i + 1] != 0x22)
        die("the descriptor does not follow its type byte");
    i += 2;
    sdp_elem(blob, i, &hs, &n);
    fields[(*nf)++] = (struct field){ i + 1, hs - 1 };
    *size = n;
    return i + hs;
}
static size_t sdp_record(int mode, uint8_t rid, uint8_t *out, size_t *added)
{
    static const uint8_t items[] = { 0x85, 0, 0x05, 0x06, 0x09, 0x20, 0x15, 0x00,
                                     0x25, 0x64, 0x75, 0x08, 0x95, 0x01, 0x81, 0x02 };
    uint8_t add[sizeof items];
    memcpy(add, items, sizeof items);
    add[1] = rid;
    size_t len = SDP_LEN[mode];
    memcpy(out, mem(RECORD[mode]), len);
    struct field fields[8];
    int nf;
    size_t n, start = descriptor_place(out, len, fields, &nf, &n);
    if (out[start + n - 1] != 0xC0)
        die("mode %d: the descriptor does not end with a collection", mode);
    size_t at = start + n - 1;
    memmove(out + at + sizeof add, out + at, len - at);
    memcpy(out + at, add, sizeof add);
    len += sizeof add;
    for (int k = 0; k < nf; k++) {
        size_t off = fields[k].off, w = fields[k].width, v = 0;
        for (size_t x = 0; x < w; x++)
            v = v << 8 | out[off + x];
        v += sizeof add;
        if (w < 8 && v >= (size_t)1 << (8 * w))
            die("mode %d: a length no longer fits its %zu byte field", mode, w);
        for (size_t x = 0; x < w; x++)
            out[off + w - 1 - x] = (uint8_t)(v >> (8 * x));
    }
    *added = sizeof add;
    return len;
}
static void device_id(int mode, uint8_t *out)
{
    const uint8_t *blob = mem(RECORD[mode]);
    const uint8_t pnp[3] = { 0x19, 0x12, 0x00 };
    const uint8_t *start = find(blob, 0x600, pnp, 3);
    if (!start)
        die("mode %d: no PnP Information service class", mode);
    static const uint16_t attrs[4] = { 0x0205, 0x0201, 0x0202, 0x0203 };
    uint16_t v[4];
    for (int k = 0; k < 4; k++) {
        uint8_t pat[4] = { 0x09, (uint8_t)(attrs[k] >> 8), (uint8_t)attrs[k], 0x09 };
        const uint8_t *i = find(start, 0x600 - (size_t)(start - blob), pat, 4);
        if (!i)
            die("mode %d: no attribute %#06x in the Device ID record", mode, attrs[k]);
        v[k] = be16(i + 4);
    }
    out[0] = (uint8_t)v[0];
    for (int k = 1; k < 4; k++) {
        out[1 + 2 * (k - 1)] = (uint8_t)v[k];
        out[2 + 2 * (k - 1)] = (uint8_t)(v[k] >> 8);
    }
}
struct table {
    uint8_t b[1024];
    size_t n;
    uint16_t handle;
    uint16_t h_report, h_battery, h_ff13;
    uint16_t off_battery;
    int has_ff13;
};
static void add_entry(struct table *t, uint16_t uuid, const uint8_t *value, size_t len,
                      const char *mark)
{
    t->handle++;
    if (mark) {
        if (!strcmp(mark, "report"))
            t->h_report = t->handle;
        else if (!strcmp(mark, "battery")) {
            t->h_battery = t->handle;
            t->off_battery = (uint16_t)(t->n + 6);
        } else {
            t->h_ff13 = t->handle;
            t->has_ff13 = 1;
        }
    }
    if (t->n + 6 + len > sizeof t->b)
        die("the table is too long");
    uint8_t *p = t->b + t->n;
    p[0] = (uint8_t)t->handle;
    p[1] = (uint8_t)(t->handle >> 8);
    p[2] = 2;
    p[3] = (uint8_t)uuid;
    p[4] = (uint8_t)(uuid >> 8);
    p[5] = (uint8_t)len;
    memcpy(p + 6, value, len);
    t->n += 6 + len;
}
static void add_u16(struct table *t, uint16_t uuid, uint16_t v, const char *mark)
{
    uint8_t b[2] = { (uint8_t)v, (uint8_t)(v >> 8) };
    add_entry(t, uuid, b, 2, mark);
}
static struct table build_table(int mode, const struct bytes *rmap, size_t replen, int probe)
{
    struct table t = { { 0 }, 0, 0, 0, 0, 0, 0, 0 };
    uint8_t zero[64] = { 0 };
    add_u16(&t, 0x2800, 0x1800, NULL);
    add_entry(&t, 0x2803, (const uint8_t *)"\x02", 1, NULL);
    add_entry(&t, 0x2A00, (const uint8_t *)NAME, sizeof NAME - 1, NULL);
    add_entry(&t, 0x2803, (const uint8_t *)"\x02", 1, NULL);
    add_u16(&t, 0x2A01, APPEARANCE[mode], NULL);
    if (probe) {
        add_u16(&t, 0x2800, 0xFF10, NULL);
        add_entry(&t, 0x2803, (const uint8_t *)"\x18", 1, NULL);
        add_entry(&t, 0xFF13, zero, 1, "ff13");
        add_entry(&t, 0x2902, zero, 2, NULL);
    }
    add_u16(&t, 0x2800, 0x1812, NULL);
    add_entry(&t, 0x2803, (const uint8_t *)"\x02", 1, NULL);
    add_entry(&t, 0x2A4A, (const uint8_t *)"\x11\x01\x00\x02", 4, NULL);
    add_entry(&t, 0x2803, (const uint8_t *)"\x02", 1, NULL);
    add_entry(&t, 0x2A4B, rmap->b, rmap->n, NULL);
    add_entry(&t, 0x2803, (const uint8_t *)"\x04", 1, NULL);
    add_entry(&t, 0x2A4C, zero, 1, NULL);
    add_entry(&t, 0x2803, (const uint8_t *)"\x12", 1, NULL);
    if (replen > sizeof zero)
        die("mode %d: the report is longer than the table can hold", mode);
    add_entry(&t, 0x2A4D, zero, replen, "report");
    add_entry(&t, 0x2902, zero, 2, NULL);
    uint8_t ref[2] = { MAIN_REPORT[mode], 1 };
    add_entry(&t, 0x2908, ref, 2, NULL);
    add_entry(&t, 0x2803, (const uint8_t *)"\x06", 1, NULL);
    add_entry(&t, 0x2A4E, (const uint8_t *)"\x01", 1, NULL);
    add_u16(&t, 0x2800, 0x180F, NULL);
    add_entry(&t, 0x2803, (const uint8_t *)"\x12", 1, NULL);
    uint8_t full[1] = { 100 };
    add_entry(&t, 0x2A19, full, 1, "battery");
    add_entry(&t, 0x2902, zero, 2, NULL);
    add_u16(&t, 0x2800, 0x180A, NULL);
    add_entry(&t, 0x2803, (const uint8_t *)"\x02", 1, NULL);
    uint8_t pnp[7];
    device_id(mode, pnp);
    add_entry(&t, 0x2A50, pnp, 7, NULL);
    t.b[t.n++] = 0;
    t.b[t.n++] = 0;
    return t;
}
struct symbol { char name[64]; uint32_t addr; };
static struct symbol syms[256];
static int nsyms;
static uint32_t sym_addr(const char *name)
{
    for (int i = 0; i < nsyms; i++)
        if (!strcmp(syms[i].name, name))
            return syms[i].addr;
    die("the build's code defines no %s", name);
    return 0;
}
static int has_sym(const char *name)
{
    for (int i = 0; i < nsyms; i++)
        if (!strcmp(syms[i].name, name))
            return 1;
    return 0;
}
static void run(char **argv)
{
    pid_t pid = fork();
    if (pid < 0)
        die("fork: %s", strerror(errno));
    if (!pid) {
        execvp(argv[0], argv);
        fprintf(stderr, "genble: %s: %s\n", argv[0], strerror(errno));
        _exit(127);
    }
    int status;
    if (waitpid(pid, &status, 0) < 0 || !WIFEXITED(status) || WEXITSTATUS(status))
        die("%s failed", argv[0]);
}
static const struct symbol GIVEN[] = {
    { "memcpy", 0x01018268 }, { "now", 0x01020B90 }, { "elapsed", 0x01020B9C },
    { "loop_once", 0x0101986C }, { "poll_flags", 0x0101C418 }, { "memzero", 0x0101829A },
    { "restart", 0x01023290 }, { "ipc_send", 0x010202C8 }, { "cmd_42", 0x0101A2AC },
    { "set_vis", 0x0101A304 }, { "c874", 0x0101C874 }, { "c900", 0x0101C900 },
    { "bt_disconnect", 0x01018B1C }, { "ble_disconnect", 0x01018AC8 },
    { "set_ble_addr", 0x01019F44 }, { "send_b0", 0x01019DB8 }, { "led_set", 0x010232BC },
    { "flash_read", 0x01025018 }, { "flash_erase", 0x01025054 }, { "flash_write", 0x0102507C },
};
static uint8_t *assemble(const char *build, const char *dir, size_t *len)
{
    char src[512], obj[640], elf[640], bin[640], nm[640], ttext[64], defs[20][128];
    snprintf(src, sizeof src, "patches/%s.s", build);
    snprintf(obj, sizeof obj, "%s/p.o", dir);
    snprintf(elf, sizeof elf, "%s/p.elf", dir);
    snprintf(bin, sizeof bin, "%s/p.bin", dir);
    snprintf(nm, sizeof nm, "%s/p.nm", dir);
    snprintf(ttext, sizeof ttext, "-Ttext=%#x", CODE);
    char *as[] = { "arm-none-eabi-as", "-mcpu=cortex-m0", src, "-o", obj, NULL };
    run(as);
    char *ld[32];
    int n = 0;
    ld[n++] = "arm-none-eabi-ld";
    ld[n++] = ttext;
    ld[n++] = "-e";
    ld[n++] = "gatt_setup";
    ld[n++] = obj;
    ld[n++] = "-o";
    ld[n++] = elf;
    for (size_t i = 0; i < sizeof GIVEN / sizeof *GIVEN; i++) {
        snprintf(defs[i], sizeof defs[i], "--defsym=%.63s=%#x", GIVEN[i].name, GIVEN[i].addr);
        ld[n++] = defs[i];
    }
    ld[n] = NULL;
    run(ld);
    char *oc[] = { "arm-none-eabi-objcopy", "-O", "binary", elf, bin, NULL };
    run(oc);
    char cmd[1400];
    snprintf(cmd, sizeof cmd, "arm-none-eabi-nm %.639s > %.639s", elf, nm);
    char *sh[] = { "sh", "-c", cmd, NULL };
    run(sh);
    size_t nlen;
    uint8_t *text = slurp(nm, &nlen);
    char *line = strtok((char *)text, "\n");
    while (line) {
        char addr[32], type[8], name[64];
        if (sscanf(line, "%31s %7s %63s", addr, type, name) == 3 && strlen(type) == 1
            && (type[0] == 'T' || type[0] == 't') && nsyms < 256) {
            snprintf(syms[nsyms].name, sizeof syms[nsyms].name, "%s", name);
            syms[nsyms].addr = (uint32_t)strtoul(addr, NULL, 16);
            nsyms++;
        }
        line = strtok(NULL, "\n");
    }
    free(text);
    return slurp(bin, len);
}
static uint32_t params_address(const char *build)
{
    char path[512];
    snprintf(path, sizeof path, "patches/%s.s", build);
    size_t len;
    char *s = (char *)slurp(path, &len);
    uint32_t at = PARAMS;
    for (char *line = strtok(s, "\n"); line; line = strtok(NULL, "\n")) {
        char *p = line + strspn(line, " \t");
        if (strncmp(p, ".equ", 4))
            continue;
        p += 4;
        p += strspn(p, " \t");
        if (strncmp(p, "PARAMS,", 7))
            continue;
        p += 7;
        p += strspn(p, " \t");
        if (p[0] == '0' && (p[1] == 'x' || p[1] == 'X')) {
            at = (uint32_t)strtoul(p, NULL, 16);
            break;
        }
    }
    free(s);
    return at;
}
static FILE *out;
static void emit_comment(const char *text) { fprintf(out, "%s\n", text); }
static void emit_hex(const uint8_t *b, size_t n)
{
    for (size_t i = 0; i < n; i++)
        fprintf(out, "%s%02x", i ? "," : "", b[i]);
}
static void emit_edit(uint32_t at, const uint8_t *new, size_t n)
{
    fprintf(out, "%08x ", at);
    for (size_t i = 0; i < n; i++) {
        size_t off = at - BASE + i;
        fprintf(out, "%s%02x", i ? "," : "", off < IMG_LEN ? IMG[off] : 0xFF);
    }
    fputc(' ', out);
    emit_hex(new, n);
    fputc('\n', out);
}
static void emit_bl(uint32_t at, uint32_t dst)
{
    int32_t off = ((int32_t)dst - (int32_t)(at + 4)) >> 1;
    uint8_t b[4];
    uint16_t hi = (uint16_t)(0xF000 | ((off >> 11) & 0x7FF)), lo = (uint16_t)(0xF800 | (off & 0x7FF));
    b[0] = (uint8_t)hi;
    b[1] = (uint8_t)(hi >> 8);
    b[2] = (uint8_t)lo;
    b[3] = (uint8_t)(lo >> 8);
    emit_edit(at, b, 4);
}
static size_t length_bytes(const char *kind, const uint8_t *old, size_t added, size_t want,
                           uint8_t *new)
{
    if (!strcmp(kind, "adds")) {
        if (old[1] != 0x31 || old[0] + added > 255)
            die("an adds site does not look right: %02x %02x", old[0], old[1]);
        new[0] = (uint8_t)(old[0] + added);
        new[1] = 0x31;
        return 2;
    }
    if (!strcmp(kind, "subs")) {
        if (old[1] != 0x39 || old[0] < added)
            die("a subs site does not look right: %02x %02x", old[0], old[1]);
        new[0] = (uint8_t)(old[0] - added);
        new[1] = 0x39;
        return 2;
    }
    if (old[0] != 0xFF || old[1] != 0x21 || old[2] != 0xFD || old[3] != 0x31)
        die("a pair site does not look right");
    for (int shift = 0; shift < 8; shift++)
        if (want % (1u << shift) == 0 && (want >> shift) < 256) {
            uint16_t a = (uint16_t)(0x2100 | (want >> shift)), b = (uint16_t)((shift << 6) | 9);
            new[0] = (uint8_t)a;
            new[1] = (uint8_t)(a >> 8);
            new[2] = (uint8_t)b;
            new[3] = (uint8_t)(b >> 8);
            return 4;
        }
    die("%zu does not fit a movs and a shift", want);
    return 0;
}
int main(int argc, char **argv)
{
    const char *build = argc > 1 ? argv[1] : "ble_hid";
    IMG = slurp("firmware/decrypted/zero2_v1.08.s1.bin", &IMG_LEN);
    unpack_ram();
    PARAMS = params_address(build);
    const char *rt = getenv("XDG_RUNTIME_DIR");
    char dir[512];
    snprintf(dir, sizeof dir, "%s/zero2/%s", rt && *rt ? rt : "/tmp", build);
    char mk[600];
    snprintf(mk, sizeof mk, "mkdir -p %s", dir);
    char *sh[] = { "sh", "-c", mk, NULL };
    run(sh);
    uint8_t params[MODES * 24], tables[4096];
    size_t nparams = 0, ntables = 0;
    uint32_t at = PARAMS + MODES * 24;
    char report[MODES * 2][256];
    int nreport = 0;
    for (int mode = 0; mode < MODES; mode++) {
        struct bytes desc = descriptor(mode);
        struct bytes rmap = minimal(&desc, MAIN_REPORT[mode]);
        check(&rmap);
        size_t replen = report_bytes(&rmap, MAIN_REPORT[mode]);
        size_t limit = 0x4AC5 - 0x4975;
        struct table t = build_table(mode, &rmap, replen, 1);
        if (t.n > limit)
            t = build_table(mode, &rmap, replen, 0);
        if (t.n > limit)
            die("mode %d: the table is %zu bytes, the core keeps data from 0x4AC5", mode, t.n);
        uint8_t *p = params + nparams;
        memset(p, 0, 24);
        p[0] = (uint8_t)at; p[1] = (uint8_t)(at >> 8); p[2] = (uint8_t)(at >> 16); p[3] = (uint8_t)(at >> 24);
        p[4] = (uint8_t)t.n; p[5] = (uint8_t)(t.n >> 8);
        p[6] = (uint8_t)APPEARANCE[mode]; p[7] = (uint8_t)(APPEARANCE[mode] >> 8);
        p[8] = MAIN_REPORT[mode];
        p[9] = (uint8_t)replen;
        p[10] = (uint8_t)MAIN_MTU[mode]; p[11] = (uint8_t)(MAIN_MTU[mode] >> 8);
        p[12] = (uint8_t)t.h_report; p[13] = (uint8_t)(t.h_report >> 8);
        p[14] = (uint8_t)t.h_battery; p[15] = (uint8_t)(t.h_battery >> 8);
        p[16] = (uint8_t)t.off_battery; p[17] = (uint8_t)(t.off_battery >> 8);
        p[18] = (uint8_t)(t.has_ff13 ? t.h_ff13 : 0); p[19] = (uint8_t)((t.has_ff13 ? t.h_ff13 : 0) >> 8);
        p[20] = CLASSIC_BATTERY[mode];
        nparams += 24;
        memcpy(tables + ntables, t.b, t.n);
        ntables += t.n;
        char *r = report[nreport++];
        int rn = snprintf(r, 200,
                          "mode %d: map %zu, report %zu, table %zu at %#x, mtu %u, "
                          "report handle %#x, battery %#x", mode, rmap.n, replen, t.n, at,
                          MAIN_MTU[mode], t.h_report, t.h_battery);
        if (t.has_ff13)
            snprintf(r + rn, 48, ", probe %#x", t.h_ff13);
        else
            snprintf(r + rn, 48, ", no probe");
        at += t.n;
    }
    size_t code_len;
    uint8_t *code = assemble(build, dir, &code_len);
    static uint8_t records[4096];
    size_t nrecords = 0;
    struct { uint32_t at; uint8_t b[8]; size_t n; } sites[16];
    int nsites = 0;
    uint32_t addr_sdp = SDP_AT;
    for (int mode = 0; mode < MODES; mode++) {
        if (!CLASSIC_BATTERY[mode])
            continue;
        uint8_t blob[1024];
        size_t added, len = sdp_record(mode, CLASSIC_BATTERY[mode], blob, &added);
        sites[nsites].at = SDP_PTR[mode];
        sites[nsites].n = 4;
        sites[nsites].b[0] = (uint8_t)addr_sdp;
        sites[nsites].b[1] = (uint8_t)(addr_sdp >> 8);
        sites[nsites].b[2] = (uint8_t)(addr_sdp >> 16);
        sites[nsites].b[3] = (uint8_t)(addr_sdp >> 24);
        nsites++;
        for (int k = 0; k < 2; k++) {
            const struct site *s = &LENGTH_SITE[mode][k];
            if (!s->kind)
                continue;
            size_t n = !strcmp(s->kind, "pair") ? 4 : 2;
            sites[nsites].at = s->at;
            sites[nsites].n = length_bytes(s->kind, IMG + (s->at - BASE), added,
                                           SDP_LEN[mode] + added, sites[nsites].b);
            if (sites[nsites].n != n)
                die("a length site came out the wrong size");
            nsites++;
        }
        snprintf(report[nreport++], 256,
                 "mode %d: SDP record %zu bytes at %#x, battery report %#04x, core 0x4683 to %#06x",
                 mode, len, addr_sdp, CLASSIC_BATTERY[mode], (unsigned)(0x4683 + len - 1));
        memcpy(records + nrecords, blob, len);
        nrecords += len;
        addr_sdp += len;
    }
    if (addr_sdp > BASE + SIZE)
        die("the records do not fit in the image");
    if (CODE + code_len > PARAMS)
        die("the code is %zu bytes, the parameters start at %#x", code_len, PARAMS);
    if (PARAMS + nparams + ntables > BASE + SIZE)
        die("the tables do not fit in the image");
    char path[512];
    snprintf(path, sizeof path, "patches/%s.txt", build);
    out = fopen(path, "w");
    if (!out)
        die("%s: %s", path, strerror(errno));
    fprintf(out, "base firmware/decrypted/zero2_v1.08.s1.bin\n");
    fprintf(out, "version 108\n");
    fprintf(out, "size %#x\n", SIZE);
    emit_comment("# command 0x04 BLE name: \"80EL\" to \"Zero 2 BLE\"");
    emit_edit(0x0102919C, (const uint8_t *)NAME, sizeof NAME - 1);
    emit_comment("# command 0x02 visibility (FUN_0101a304): vis_bits works the bits out from the links, so classic is not");
    emit_comment("# connectable while a BLE link is up and nothing advertises while either link is up");
    emit_bl(0x0101A310, sym_addr("vis_bits"));
    emit_comment("# start-up: the BLE address goes through ble_addr, which gives every mode its own");
    emit_bl(0x0101A5F0, sym_addr("ble_addr"));
    emit_comment("# start-up: gatt_setup writes the mode's GATT table, advertising data and MTU, in place of FUN_0101a2ac");
    emit_bl(0x0101A6B0, sym_addr("gatt_setup"));
    emit_comment("# event 0x02 (BLE connected): on_ble_up drops classic, in place of the 6 s timer that restarted the pad");
    emit_bl(0x01019AE4, sym_addr("on_ble_up"));
    emit_comment("# event 0x05 (BLE disconnected): on_ble_down, which calls FUN_0101c874 and lets classic back in");
    emit_bl(0x01019B3A, sym_addr("on_ble_down"));
    emit_comment("# event 0xb0 (classic HID connected): on_classic_up drops a BLE link, in place of FUN_0101c900");
    emit_bl(0x01019B5A, sym_addr("on_classic_up"));
    emit_comment("# event 0xb6 (classic HID disconnected): on_classic_down stores the state and advertises again");
    emit_bl(0x01019B80, sym_addr("on_classic_down"));
    emit_comment("# reconnect routine FUN_01023148: reconnect_blocked keeps it from paging the classic host while BLE is up");
    emit_bl(0x01023152, sym_addr("reconnect_blocked"));
    emit_comment("# report builder FUN_0101f1d4: link_state makes it build the mode's report for a BLE link as for classic");
    emit_bl(0x0101F240, sym_addr("link_state"));
    emit_comment("# FUN_01024e8c: send_report notifies the mode's report on the BLE Report handle, then sends 0xb0 as before");
    emit_bl(0x01024E9A, sym_addr("send_report"));
    emit_comment("# event 0x08 (BLE write) on the 0xFF13 handle: call the probe with the written bytes");
    {
        uint8_t b[8] = { 0x08, 0xA8, 0xB1, 0x1E };
        uint32_t dst = sym_addr("probe");
        int32_t off = ((int32_t)dst - (int32_t)(0x01019918 + 4)) >> 1;
        uint16_t hi = (uint16_t)(0xF000 | ((off >> 11) & 0x7FF)), lo = (uint16_t)(0xF800 | (off & 0x7FF));
        b[4] = (uint8_t)hi;
        b[5] = (uint8_t)(hi >> 8);
        b[6] = (uint8_t)lo;
        b[7] = (uint8_t)(lo >> 8);
        emit_edit(0x01019914, b, 8);
    }
    if (has_sym("poll_sync")) {
        emit_comment("# the poll loop FUN_0101ca40: poll_sync sets the visibility again whenever the links change, in");
        emit_comment("# place of its first call (FUN_0101c418, whose answer it returns)");
        emit_bl(0x0101CA42, sym_addr("poll_sync"));
    }
    if (has_sym("pair_read")) {
        emit_comment("# start-up's read of the core's pairing records, and the write-back on event 0x0d: every mode");
        emit_comment("# keeps its own set, on its own flash page (see \"The five pairing slots\" in docs/findings.md)");
        emit_bl(0x0101A638, sym_addr("pair_read"));
        emit_bl(0x01019BB8, sym_addr("pair_write"));
    }
    if (has_sym("led_link")) {
        emit_comment("# the LED pattern chooser FUN_010242f0: it lights the LED solid while a classic link is up, and");
        emit_comment("# led_link answers that question for a BLE link too, so a BLE host gets the same solid LED");
        emit_bl(0x01024354, sym_addr("led_link"));
    }
    if (has_sym("hook_rx")) {
        emit_comment("# IPC receive handler FUN_01018e0c (IRQ 11): hook_rx keeps every core event in a ring, in place of now()");
        emit_bl(0x01018E20, sym_addr("hook_rx"));
        emit_comment("# run loop data source at 0x2200C: drain runs FUN_0101986c and sends the kept events as notifications");
        uint32_t v = sym_addr("drain") | 1;
        uint8_t b[4] = { (uint8_t)v, (uint8_t)(v >> 8), (uint8_t)(v >> 16), (uint8_t)(v >> 24) };
        emit_edit(0x0101A77C, b, 4);
    }
    {
        char line[256];
        snprintf(line, sizeof line,
                 "# the code, in the flash the image gains after the program (source: patches/%s.s)", build);
        emit_comment(line);
        emit_edit(CODE, code, code_len);
        emit_comment("# the mode parameters and the five GATT tables (built by tools/genble.c)");
        uint8_t *data = malloc(nparams + ntables);
        memcpy(data, params, nparams);
        memcpy(data + nparams, tables, ntables);
        emit_edit(PARAMS, data, nparams + ntables);
        free(data);
    }
    if (nrecords) {
        emit_comment("# the SDP record of every mode that does not report its battery over classic, with a battery");
        emit_comment("# report added to its HID descriptor, and the pointer and length the program passes for it");
        for (int i = 0; i < nsites; i++)
            emit_edit(sites[i].at, sites[i].b, sites[i].n);
        emit_edit(SDP_AT, records, nrecords);
    }
    fclose(out);
    for (int i = 0; i < nreport; i++)
        puts(report[i]);
    printf("code %zu bytes at %#x, tables %zu bytes at %#x\n", code_len, CODE, nparams + ntables,
           PARAMS);
    free(code);
    free(IMG);
    return 0;
}
