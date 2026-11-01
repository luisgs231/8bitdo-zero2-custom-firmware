#include <errno.h>
#include <fcntl.h>
#include <math.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#define BLOCK 128
#define HEADER_SIZE 28
#define PROGRAM_BASE 0x01018000u
#define ZERO2_PID 0x9018
static void die(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    fputs("zero2: ", stderr);
    vfprintf(stderr, fmt, ap);
    fputc('\n', stderr);
    va_end(ap);
    exit(1);
}
static void *xmalloc(size_t n)
{
    void *p = malloc(n ? n : 1);
    if (!p)
        die("out of memory");
    return p;
}
static uint8_t *slurp(const char *path, size_t *len)
{
    FILE *f = fopen(path, "rb");
    if (!f)
        die("%s: %s", path, strerror(errno));
    if (fseek(f, 0, SEEK_END))
        die("%s: not a regular file", path);
    long n = ftell(f);
    rewind(f);
    uint8_t *b = xmalloc((size_t)n);
    if (n && fread(b, 1, (size_t)n, f) != (size_t)n)
        die("%s: short read", path);
    fclose(f);
    *len = (size_t)n;
    return b;
}
static void spit(const char *path, const uint8_t *b, size_t n)
{
    FILE *f = fopen(path, "wb");
    if (!f)
        die("%s: %s", path, strerror(errno));
    if (n && fwrite(b, 1, n, f) != n)
        die("%s: short write", path);
    fclose(f);
}
static uint32_t rd32(const uint8_t *b) { return b[0] | b[1] << 8 | b[2] << 16 | (uint32_t)b[3] << 24; }
static void wr32(uint8_t *b, uint32_t v) { b[0] = v; b[1] = v >> 8; b[2] = v >> 16; b[3] = v >> 24; }
static void wr16(uint8_t *b, uint16_t v) { b[0] = v; b[1] = v >> 8; }
static const uint16_t KEY_WORDS[] = {
    0xF428, 0x50C3, 0x3071, 0x722A, 0x848D, 0x0DD7, 0x5B3E, 0x56EF, 0x3AD3,
    0x510A, 0x0147, 0x417A, 0x886C, 0x12AE, 0x3C9C, 0x5DD3, 0x2D6E, 0x615B,
    0xD68B, 0x5BCC, 0xD3E3, 0x2D48, 0xC15B, 0xA342, 0x5E54, 0x4D90, 0xAF30,
    0x7A74, 0x05A8, 0x5E0B, 0x53B4, 0xC56A, 0xDB56, 0x6F88, 0x367E, 0x3814,
    0x4E53, 0x184E, 0x2227, 0x0024, 0x7705, 0x4FD0, 0x42AE, 0x71C5, 0x5004,
    0xBFF0, 0x1E71, 0x3330, 0xF02A, 0x470B, 0x4142, 0x2EA0, 0x56EC, 0x424F,
    0x7982, 0x1361, 0xD7C3, 0x0DC8, 0x1552, 0x5537, 0xA2B9, 0x4E96, 0x7243,
    0xA00A, 0xC620, 0xED93, 0xE24F, 0x82DC, 0x0BE4, 0x240B, 0x7118, 0xDD34,
    0xF0D2, 0xE406, 0x7F07, 0xF800, 0x327B, 0xDB9C, 0x547A, 0xFCC2, 0x8835,
    0x539A, 0x320D, 0xF492, 0xE6EC, 0x26BC, 0x6FC3, 0xA9C8, 0x00E9, 0xC11B,
    0xD224, 0x199A, 0x2484, 0x1F47, 0xCE36, 0x2F14, 0x9972, 0x6801, 0x6C86,
    0x5C33, 0x8274, 0x0E1F, 0xF5F6, 0x885F, 0x02B3, 0x9605, 0x39BC, 0xDBBD,
    0x9E2D, 0xED7D, 0x5968, 0xE436, 0xA8DD, 0x1981, 0x5B9A, 0x93F4, 0x91D5,
    0x4CBE, 0x5CFC, 0x8FC3, 0x1484, 0x101C, 0x4251, 0x17BF, 0xFB91, 0xF156,
    0x0B4A, 0x2205, 0x949F, 0x1E4E, 0xC9F0, 0xB66C, 0xACCF, 0x5C44, 0xE3BB,
    0x5BFD, 0xF3EC, 0xA47C, 0x6BC8, 0x46B3, 0xB5CD, 0xD223, 0x7022, 0x046F,
    0xB7C8, 0x0B51, 0xD416, 0x5041, 0x95D1, 0xB7F0, 0x456F, 0xEC16, 0xE119,
    0x8BD4, 0x43AD, 0xC04F, 0x16B2, 0x802D, 0xD7E2, 0x16AC, 0x833F, 0x1660,
    0x993E, 0xD4F4, 0x9AC7, 0xE9A1, 0x12A5, 0x0504, 0x931E, 0xECC2, 0x157D,
    0xE013, 0x8562, 0x8693, 0x9237, 0xD7F7, 0xC59D, 0xEAC2, 0x7CD0, 0xBA88,
    0x5BD1, 0x09B5, 0x9C15, 0xACC0, 0xAA02, 0x0FDE, 0x434D, 0xE9E5, 0x8BE7,
    0x601E, 0x8B55, 0x2E39, 0x1C1D, 0x0CDC, 0x1E81, 0xE405, 0x82AF, 0xF6C2,
    0x53E9, 0x3E0A, 0x09DD, 0x173E, 0xA207, 0xD23D, 0x5DDF, 0x182E, 0x1A62,
    0xC02E, 0xEDB9, 0x0D6A, 0x6687, 0x37B4, 0x1EDC, 0xEACD, 0xC515, 0x495B,
    0x39B2, 0x9972, 0x9E49, 0xAC4E, 0xD364, 0x96B7, 0xBBB5, 0x412E, 0x8BB7,
    0xA647, 0x3A9C, 0x93CF, 0x0AD3, 0x388C, 0x9C1C, 0x8268, 0x0BCD, 0xC814,
    0x6521, 0x608A, 0x7120, 0xDBCA, 0xD2D0, 0xFA37, 0xC9A5, 0x56C8, 0x2066,
    0xF8C9, 0x1872, 0x352B, 0x1908, 0x991E, 0xA478, 0x45A3, 0x0E8C, 0x2486,
    0xE293, 0x8D55, 0x2912, 0x2129
};
#define KEYS (sizeof KEY_WORDS / sizeof *KEY_WORDS)
#define PAIR_FLIP 0xF9
enum { YICHIP, GD32 };
static const struct {
    const char *name;
    uint32_t walk, mul, turn_key, turn_carry, load_addr;
    long blocks;
} FORMAT[2] = {
    { "yichip", 0xEE97FAFAu, 0x01200210u, 16, 18, 0x01018000u, -1 },
    { "gd32", 0x92A753FAu, 0x80000301u, 18, 3, 0x08003400u, KEYS },
};
static const uint8_t YC_FOLD[2][8] = { { 0x00, 0x82, 0x83, 0x81, 0x03, 0x81, 0x83, 0x81 },
                                       { 0x86, 0x83, 0x81, 0x82, 0x03, 0x05, 0x82, 0x82 } };
static uint32_t turn(uint32_t v, unsigned n)
{
    n &= 31;
    return n ? v >> n | v << (32 - n) : v;
}
static uint32_t block_seed(int f, uint32_t block)
{
    unsigned a = block, b = block ^ PAIR_FLIP;
    if (f == YICHIP) {
        unsigned i = (block + (block >> 8)) & 0xFF;
        a = i ^ YC_FOLD[i >> 7][i & 7];
        i ^= PAIR_FLIP;
        b = i ^ YC_FOLD[i >> 7][i & 7];
    }
    return (uint32_t)KEY_WORDS[a] << 16 | KEY_WORDS[b];
}
static uint32_t mask_for(int f, size_t word)
{
    uint32_t block = word / BLOCK, pos = word % BLOCK;
    uint32_t run = block * FORMAT[f].mul + (f == YICHIP ? block >> 8 : block / 2)
                 + pos * FORMAT[f].walk;
    return run ^ turn(block_seed(f, block), FORMAT[f].turn_key * pos);
}
static void recode(int f, const uint32_t *src, uint32_t *dst, size_t n, int encrypting)
{
    for (size_t i = 0; i < n; i++) {
        uint32_t carry = 0;
        if (i % BLOCK)
            carry = turn(encrypting ? dst[i - 1] : src[i - 1], FORMAT[f].turn_carry);
        dst[i] = encrypting ? src[i] ^ mask_for(f, i) ^ carry : src[i] ^ carry ^ mask_for(f, i);
    }
}
struct section { size_t offset; uint32_t id, addr, payload_len, pid; };
static int parse_sections(const uint8_t *raw, size_t len, struct section *s, int max)
{
    int n = 0;
    size_t off = 0;
    while (off + HEADER_SIZE <= len && n < max) {
        uint32_t payload_len = rd32(raw + off + 8);
        if (payload_len == 0 || off + HEADER_SIZE + payload_len > len)
            break;
        s[n].offset = off;
        s[n].id = rd32(raw + off);
        s[n].addr = rd32(raw + off + 4);
        s[n].payload_len = payload_len;
        s[n].pid = rd32(raw + off + 12);
        off += HEADER_SIZE + payload_len;
        n++;
    }
    return n;
}
static size_t decrypt_section(const uint8_t *raw, const struct section *s, int f,
                              uint8_t *out, size_t cap)
{
    const uint8_t *p = raw + s->offset + HEADER_SIZE;
    size_t words = s->payload_len / 4, tail = s->payload_len % 4;
    size_t n = words;
    if (FORMAT[f].blocks >= 0 && n > (size_t)FORMAT[f].blocks * BLOCK)
        n = (size_t)FORMAT[f].blocks * BLOCK;
    if (4 * n + (n == words ? tail : 0) > cap)
        die("decrypt: output does not fit");
    uint32_t *in = xmalloc(4 * words), *dec = xmalloc(4 * words);
    for (size_t i = 0; i < words; i++)
        in[i] = rd32(p + 4 * i);
    recode(f, in, dec, n, 0);
    for (size_t i = 0; i < n; i++)
        wr32(out + 4 * i, dec[i]);
    free(in);
    free(dec);
    if (n == words && tail) {
        memcpy(out + 4 * n, p + 4 * n, tail);
        return 4 * n + tail;
    }
    return 4 * n;
}
static double entropy(const uint8_t *b, size_t n)
{
    size_t count[256] = { 0 };
    for (size_t i = 0; i < n; i++)
        count[b[i]]++;
    double e = 0;
    for (int i = 0; i < 256; i++)
        if (count[i]) {
            double p = (double)count[i] / n;
            e -= p * log2(p);
        }
    return e;
}
static int detect_format(const uint8_t *raw, const struct section *s)
{
    struct section head = *s;
    if (head.payload_len > 8192)
        head.payload_len = 8192;
    uint8_t *buf = xmalloc(head.payload_len + 4);
    int hits = 0, found = -1;
    for (int f = 0; f < 2; f++) {
        size_t n = decrypt_section(raw, &head, f, buf, head.payload_len + 4);
        if (n && entropy(buf, n) < 7.5) {
            found = f;
            hits++;
        }
    }
    free(buf);
    return hits == 1 ? found : -1;
}
static uint8_t *build_section(const uint8_t *payload, size_t len, int f,
                              uint32_t version, uint32_t addr, size_t length, uint32_t pid,
                              size_t *out_len)
{
    if (!length)
        length = len + (BLOCK * 4 - len % (BLOCK * 4)) % (BLOCK * 4);
    if (len > length)
        die("payload (%zu bytes) is longer than length (%zu bytes)", len, length);
    if (!length || length % (BLOCK * 4))
        die("length (%zu bytes) is not a positive multiple of %d", length, BLOCK * 4);
    if (FORMAT[f].blocks >= 0 && length > (size_t)FORMAT[f].blocks * BLOCK * 4)
        die("length (%zu bytes) is more than %s can encrypt", length, FORMAT[f].name);
    if (!addr)
        addr = FORMAT[f].load_addr;
    size_t words = length / 4;
    uint32_t *in = xmalloc(4 * words), *enc = xmalloc(4 * words);
    for (size_t i = 0; i < words; i++) {
        uint8_t w[4] = { 0xFF, 0xFF, 0xFF, 0xFF };
        for (int k = 0; k < 4; k++)
            if (4 * i + k < len)
                w[k] = payload[4 * i + k];
        in[i] = rd32(w);
    }
    recode(f, in, enc, words, 1);
    uint8_t *out = xmalloc(HEADER_SIZE + length);
    memset(out, 0, HEADER_SIZE);
    wr32(out, version);
    wr32(out + 4, addr);
    wr32(out + 8, (uint32_t)length);
    wr32(out + 12, pid);
    for (size_t i = 0; i < words; i++)
        wr32(out + HEADER_SIZE + 4 * i, enc[i]);
    free(in);
    free(enc);
    *out_len = HEADER_SIZE + length;
    return out;
}
static int by_name(const char *name)
{
    for (int f = 0; f < 2; f++)
        if (!strcmp(name, FORMAT[f].name))
            return f;
    if (strcmp(name, "auto"))
        die("unknown format %s", name);
    return -1;
}
static int cmd_decrypt(int argc, char **argv)
{
    const char *in = NULL, *out = NULL, *want = "auto";
    int index = 0;
    for (int i = 0; i < argc; i++) {
        if (!strcmp(argv[i], "-s") && i + 1 < argc)
            index = atoi(argv[++i]);
        else if (!strcmp(argv[i], "-c") && i + 1 < argc)
            want = argv[++i];
        else if (!strcmp(argv[i], "-o") && i + 1 < argc)
            out = argv[++i];
        else if (!in)
            in = argv[i];
        else
            die("decrypt: unexpected %s", argv[i]);
    }
    if (!in || !out)
        die("usage: zero2 decrypt <in.dat> [-s section] [-c auto|gd32|yichip] -o <out.bin>");
    size_t len;
    uint8_t *raw = slurp(in, &len);
    struct section s[8];
    int n = parse_sections(raw, len, s, 8);
    if (!n)
        die("%s: no valid section header", in);
    if (index < 0 || index >= n)
        die("%s: section %d not found (%d section(s))", in, index, n);
    int f = by_name(want);
    if (f < 0) {
        f = detect_format(raw, &s[index]);
        if (f < 0)
            die("could not tell which format this is, name one with -c");
    }
    uint8_t *plain = xmalloc(s[index].payload_len + 4);
    size_t got = decrypt_section(raw, &s[index], f, plain, s[index].payload_len + 4);
    spit(out, plain, got);
    fprintf(stderr, "Section %d/%d: id=%u addr=0x%08x pid=0x%04x payload_len=%u\n",
            index, n - 1, s[index].id, s[index].addr, s[index].pid, s[index].payload_len);
    fprintf(stderr, "Wrote %zu words (%zu bytes) using %s\n", got / 4, got, FORMAT[f].name);
    free(plain);
    free(raw);
    return 0;
}
static int cmd_encrypt(int argc, char **argv)
{
    const char *in = NULL, *out = NULL, *want = NULL;
    uint32_t version = 0, addr = 0, pid = 0;
    size_t length = 0;
    int have_version = 0;
    for (int i = 0; i < argc; i++) {
        if (!strcmp(argv[i], "-c") && i + 1 < argc)
            want = argv[++i];
        else if (!strcmp(argv[i], "-v") && i + 1 < argc)
            version = strtoul(argv[++i], NULL, 0), have_version = 1;
        else if (!strcmp(argv[i], "-a") && i + 1 < argc)
            addr = strtoul(argv[++i], NULL, 0);
        else if (!strcmp(argv[i], "-l") && i + 1 < argc)
            length = strtoul(argv[++i], NULL, 0);
        else if (!strcmp(argv[i], "-p") && i + 1 < argc)
            pid = strtoul(argv[++i], NULL, 0);
        else if (!strcmp(argv[i], "-o") && i + 1 < argc)
            out = argv[++i];
        else if (!in)
            in = argv[i];
        else
            die("encrypt: unexpected %s", argv[i]);
    }
    if (!in || !out || !want || !have_version)
        die("usage: zero2 encrypt <payload.bin> -c gd32|yichip -v version [-a addr] [-l length] "
            "[-p pid] -o <out.dat>");
    size_t len, n;
    uint8_t *payload = slurp(in, &len);
    uint8_t *sec = build_section(payload, len, by_name(want), version, addr, length, pid, &n);
    spit(out, sec, n);
    fprintf(stderr, "Encrypted %zu words using %s: payload_len=%zu\n", (n - HEADER_SIZE) / 4, want,
            n - HEADER_SIZE);
    free(payload);
    free(sec);
    return 0;
}
static int hexval(int ch)
{
    if (ch >= '0' && ch <= '9')
        return ch - '0';
    if (ch >= 'a' && ch <= 'f')
        return ch - 'a' + 10;
    if (ch >= 'A' && ch <= 'F')
        return ch - 'A' + 10;
    return -1;
}
static size_t unhex(const char *s, uint8_t *out, size_t cap)
{
    size_t n = 0;
    while (*s) {
        if (*s == ',') {
            s++;
            continue;
        }
        int hi = hexval(s[0]), lo = hexval(s[1]);
        if (hi < 0 || lo < 0)
            die("patch: %s is not hex", s);
        if (n == cap)
            die("patch: edit is too long");
        out[n++] = hi << 4 | lo;
        s += 2;
    }
    return n;
}
static int mkdir_p(const char *path)
{
    char buf[4096];
    snprintf(buf, sizeof buf, "%s", path);
    for (char *p = buf + 1; *p; p++)
        if (*p == '/') {
            *p = 0;
            mkdir(buf, 0777);
            *p = '/';
        }
    return mkdir(buf, 0777);
}
static int cmd_patch(int argc, char **argv)
{
    if (argc != 1)
        die("usage: zero2 patch <patches/NAME.txt>");
    const char *path = argv[0];
    FILE *f = fopen(path, "r");
    if (!f)
        die("%s: %s", path, strerror(errno));
    char base[4096] = "";
    uint32_t version = 0;
    size_t size = 0;
    uint8_t *img = NULL;
    size_t len = 0, cap = 0;
    int edits = 0;
    char line[1 << 16];
    while (fgets(line, sizeof line, f)) {
        char *hash = strchr(line, '#');
        if (hash)
            *hash = 0;
        char *p = line + strspn(line, " \t\r\n");
        size_t end = strlen(p);
        while (end && strchr(" \t\r\n", p[end - 1]))
            p[--end] = 0;
        if (!*p)
            continue;
        char a[4096], b[1 << 15], c[1 << 15];
        int fields = sscanf(p, "%4095s %32767s %32767s", a, b, c);
        if (!strcmp(a, "base")) {
            snprintf(base, sizeof base, "%.4095s", b);
            img = slurp(base, &len);
            cap = len;
            continue;
        }
        if (!strcmp(a, "version")) {
            version = strtoul(b, NULL, 0);
            continue;
        }
        if (!strcmp(a, "size")) {
            size = strtoul(b, NULL, 0);
            continue;
        }
        if (fields != 3)
            die("%s: cannot read \"%s\"", path, p);
        if (!img)
            die("%s: an edit before the base", path);
        if (size && cap < size) {
            img = realloc(img, size);
            if (!img)
                die("out of memory");
            memset(img + len, 0xFF, size - len);
            cap = len = size;
        }
        uint32_t at = strtoul(a, NULL, 16);
        static uint8_t old[1 << 14], new[1 << 14];
        size_t no = unhex(b, old, sizeof old), nn = unhex(c, new, sizeof new);
        size_t off = at - PROGRAM_BASE;
        if (off + no > len || off + nn > len)
            die("%s: 0x%08x is past the image", path, at);
        if (memcmp(img + off, old, no))
            die("0x%08x: expected %02x... found %02x...", at, old[0], img[off]);
        memcpy(img + off, new, nn);
        edits++;
    }
    fclose(f);
    if (!img)
        die("%s: no base", path);
    if (len % 4) {
        img = realloc(img, len + 4 - len % 4);
        if (!img)
            die("out of memory");
        memset(img + len, 0xFF, 4 - len % 4);
        len += 4 - len % 4;
    }
    const char *slash = strrchr(path, '/');
    char name[256];
    snprintf(name, sizeof name, "%s", slash ? slash + 1 : path);
    char *dot = strrchr(name, '.');
    if (dot)
        *dot = 0;
    char dir[512], out[1024];
    snprintf(dir, sizeof dir, "out/%s", name);
    mkdir_p(dir);
    snprintf(out, sizeof out, "%s/%s.plain", dir, name);
    spit(out, img, len);
    size_t n;
    uint8_t *sec = build_section(img, len, YICHIP, version, PROGRAM_BASE, len, ZERO2_PID, &n);
    snprintf(out, sizeof out, "%s/%s.dat", dir, name);
    spit(out, sec, n);
    printf("%s: %d edits, %zu bytes\n", out, edits, len);
    free(sec);
    free(img);
    return 0;
}
enum { OP_WRITE = 3, OP_ERASE = 4, OP_READ = 5, OP_REBOOT = 7, OP_PID = 8 };
#define PAYLOAD_MAX 46
#define LOADER_TOP 0x5000
static uint16_t crc_modbus(const uint8_t *d, size_t n)
{
    uint16_t c = 0xFFFF;
    for (size_t i = 0; i < n; i++) {
        c ^= d[i];
        for (int k = 0; k < 8; k++)
            c = (c & 1) ? (c >> 1) ^ 0xA001 : c >> 1;
    }
    return c;
}
static int open_pad(const char *path)
{
    int fd = open(path, O_RDWR);
    if (fd < 0)
        die("%s: %s", path, strerror(errno));
    return fd;
}
static int waitable(int fd, double timeout)
{
    fd_set r;
    FD_ZERO(&r);
    FD_SET(fd, &r);
    struct timeval tv = { (long)timeout, (long)((timeout - (long)timeout) * 1e6) };
    return select(fd + 1, &r, NULL, NULL, &tv) > 0;
}
static void drain(int fd)
{
    uint8_t buf[64];
    while (waitable(fd, 0))
        if (read(fd, buf, sizeof buf) <= 0)
            break;
}
static int send_op(int fd, int op, uint32_t params, const uint8_t *data, size_t len,
                   uint32_t total, uint32_t offset, double timeout, uint8_t *reply, int wait)
{
    if ((op == OP_ERASE || op == OP_WRITE) && offset < LOADER_TOP)
        die("refusing op %d at 0x%x: that is the bootloader", op, offset);
    uint8_t pkt[65] = { 0 };
    pkt[0] = 0;
    pkt[1] = 5;
    wr16(pkt + 2, op);
    wr16(pkt + 4, params);
    wr16(pkt + 6, (uint16_t)len);
    wr16(pkt + 8, len ? crc_modbus(data, len) : 0);
    wr32(pkt + 10, total);
    wr32(pkt + 14, offset);
    if (len) {
        if (len > sizeof pkt - 18)
            die("packet too long");
        memcpy(pkt + 18, data, len);
    }
    drain(fd);
    if (write(fd, pkt, sizeof pkt) != (ssize_t)sizeof pkt)
        die("write: %s", strerror(errno));
    if (!wait)
        return 0;
    if (!waitable(fd, timeout))
        return -1;
    if (read(fd, reply, 64) <= 0)
        die("read: %s", strerror(errno));
    return 0;
}
static int op_answered(const uint8_t *reply, int op)
{
    return (reply[2] | reply[3] << 8) == 0 && (reply[4] | reply[5] << 8) == op;
}
static void must_send(int fd, int op, const uint8_t *data, size_t len, uint32_t total,
                      uint32_t offset, double timeout, uint8_t *reply)
{
    for (int tries = 4; tries; tries--) {
        if (send_op(fd, op, 0, data, len, total, offset, timeout, reply, 1) < 0) {
            fprintf(stderr, "  no reply to op %d at 0x%x, trying again\n", op, offset);
            continue;
        }
        if (op_answered(reply, op))
            return;
        die("op %d at 0x%x was refused: %02x %02x %02x %02x", op, offset, reply[2], reply[3],
            reply[4], reply[5]);
    }
    die("op %d at 0x%x never answered", op, offset);
}
static int cmd_probe(int argc, char **argv)
{
    if (argc != 1)
        die("usage: zero2 probe <hidraw>");
    int fd = open_pad(argv[0]);
    uint8_t r[64] = { 0 };
    if (send_op(fd, OP_PID, 0, NULL, 0, 4, 0, 1.0, r, 1) < 0)
        die("no reply: is the pad in boot mode (hold L + R + START while plugging in USB)");
    printf("boot mode, pid 0x%x\n", rd32(r + 18));
    return 0;
}
static int cmd_read(int argc, char **argv)
{
    if (argc != 4)
        die("usage: zero2 read <hidraw> <addr> <n> <out.bin>");
    int fd = open_pad(argv[0]);
    uint32_t addr = strtoul(argv[1], NULL, 0), n = strtoul(argv[2], NULL, 0);
    uint8_t *out = xmalloc(n + 32), r[64];
    uint32_t refused = 0;
    for (uint32_t o = 0; o < n; o += 32) {
        int got = 0;
        for (int attempt = 0; attempt < 4 && !got; attempt++) {
            if (send_op(fd, OP_READ, 0, NULL, 0, 32, addr + o, 3.0, r, 1) < 0)
                continue;
            if (!op_answered(r, OP_READ))
                break;
            got = 1;
        }
        if (got) {
            memcpy(out + o, r + 18, 32);
        } else {
            memset(out + o, 0xFF, 32);
            refused += 32;
        }
        if (o % 0x2000 == 0)
            fprintf(stderr, "\r  read 0x%06x/0x%x", o, n), fflush(stderr);
    }
    fprintf(stderr, "\r  read 0x%06x/0x%x\n", n, n);
    spit(argv[3], out, n);
    printf("%s: 0x%x bytes from 0x%x", argv[3], n, addr);
    if (refused)
        printf(", 0x%x refused and left as FF", refused);
    putchar('\n');
    free(out);
    return 0;
}
static int cmd_wipe(int argc, char **argv)
{
    if (argc != 2)
        die("usage: zero2 wipe <hidraw> <addr>");
    int fd = open_pad(argv[0]);
    uint32_t addr = strtoul(argv[1], NULL, 0);
    if (addr < LOADER_TOP)
        die("0x%x is the bootloader", addr);
    uint8_t r[64];
    must_send(fd, OP_ERASE, NULL, 0, 0x1000, addr, 60.0, r);
    uint8_t back[0x1000];
    for (uint32_t o = 0; o < 0x1000; o += 32) {
        must_send(fd, OP_READ, NULL, 0, 32, addr + o, 3.0, r);
        memcpy(back + o, r + 18, 32);
    }
    int left = 0;
    for (int i = 0; i < 0x1000; i++)
        left += back[i] != 0xFF;
    if (left)
        die("%d of 4096 bytes are not FF", left);
    printf("erased 4 KB at 0x%x\n", addr);
    return 0;
}
static int cmd_reset(int argc, char **argv)
{
    if (argc != 1)
        die("usage: zero2 reset <hidraw>");
    send_op(open_pad(argv[0]), OP_REBOOT, 0, NULL, 0, 0, 0, 0, NULL, 0);
    printf("reset sent\n");
    return 0;
}
static int cmd_jump(int argc, char **argv)
{
    if (argc != 1)
        die("usage: zero2 jump <hidraw>");
    int fd = open_pad(argv[0]);
    uint8_t pkt[64] = { 0x81, 5, 0, 0x51, 0 };
    if (write(fd, pkt, sizeof pkt) != (ssize_t)sizeof pkt)
        die("write: %s", strerror(errno));
    printf("jump sent\n");
    return 0;
}
static int cmd_flash(int argc, char **argv)
{
    if (argc < 2)
        die("usage: zero2 flash <hidraw> <file.dat> [--plain <file.plain>] [--no-reset]");
    const char *plain_path = NULL;
    int reset = 1;
    for (int i = 2; i < argc; i++) {
        if (!strcmp(argv[i], "--plain") && i + 1 < argc)
            plain_path = argv[++i];
        else if (!strcmp(argv[i], "--no-reset"))
            reset = 0;
        else
            die("flash: unexpected %s", argv[i]);
    }
    size_t len;
    uint8_t *dat = slurp(argv[1], &len);
    if (len < HEADER_SIZE)
        die("%s: not a .dat", argv[1]);
    uint32_t ver = rd32(dat), addr = rd32(dat + 4), size = rd32(dat + 8), pid = rd32(dat + 12);
    if (len < HEADER_SIZE + size)
        die("%s: truncated .dat", argv[1]);
    const uint8_t *img = dat + HEADER_SIZE;
    printf("file: version 0x%x, addr 0x%x, size 0x%x, pid 0x%x\n", ver, addr, size, pid);
    int fd = open_pad(argv[0]);
    uint8_t r[64];
    if (send_op(fd, OP_PID, 0, NULL, 0, 4, 0, 1.0, r, 1) < 0)
        die("no reply: is the pad in boot mode");
    uint32_t devpid = rd32(r + 18);
    printf("device pid 0x%x\n", devpid);
    if ((devpid & 0xFFFF) != (pid & 0xFFFF))
        die("PID mismatch, refusing to flash");
    time_t t0 = time(NULL);
    must_send(fd, OP_ERASE, NULL, 0, size, addr, 600.0, r);
    printf("erased in %lds\n", (long)(time(NULL) - t0));
    t0 = time(NULL);
    for (uint32_t o = 0; o < size; o += PAYLOAD_MAX) {
        uint32_t n = size - o < PAYLOAD_MAX ? size - o : PAYLOAD_MAX;
        must_send(fd, OP_WRITE, img + o, n, size, addr + o, 3.0, r);
        if (o % 0x2000 < PAYLOAD_MAX)
            printf("  wrote 0x%06x/0x%x  %lds\n", o, size, (long)(time(NULL) - t0)), fflush(stdout);
    }
    printf("verifying by readback...\n");
    uint8_t *back = xmalloc(size + 32);
    for (uint32_t o = 0; o < size; o += 32) {
        must_send(fd, OP_READ, NULL, 0, 32, addr + o, 3.0, r);
        memcpy(back + o, r + 18, 32);
    }
    const uint8_t *want = img;
    size_t want_len = size;
    uint8_t *plain = NULL;
    if (plain_path) {
        plain = slurp(plain_path, &want_len);
        want = plain;
    }
    size_t bad = 0;
    for (size_t i = 0; i < size && i < want_len; i++)
        bad += back[i] != want[i];
    if (bad)
        die("verify: %zu bytes differ", bad);
    printf("verify: OK\n");
    if (reset) {
        send_op(fd, OP_REBOOT, 0, NULL, 0, 0, 0, 0, NULL, 0);
        printf("reset sent\n");
    }
    free(back);
    free(plain);
    free(dat);
    return 0;
}
int main(int argc, char **argv)
{
    if (argc < 2) {
        fputs("usage: zero2 decrypt|encrypt|patch|probe|read|flash|wipe|reset|jump ...\n", stderr);
        return 2;
    }
    const char *cmd = argv[1];
    int n = argc - 2;
    char **a = argv + 2;
    if (!strcmp(cmd, "decrypt"))
        return cmd_decrypt(n, a);
    if (!strcmp(cmd, "encrypt"))
        return cmd_encrypt(n, a);
    if (!strcmp(cmd, "patch"))
        return cmd_patch(n, a);
    if (!strcmp(cmd, "probe"))
        return cmd_probe(n, a);
    if (!strcmp(cmd, "read"))
        return cmd_read(n, a);
    if (!strcmp(cmd, "flash"))
        return cmd_flash(n, a);
    if (!strcmp(cmd, "wipe"))
        return cmd_wipe(n, a);
    if (!strcmp(cmd, "reset"))
        return cmd_reset(n, a);
    if (!strcmp(cmd, "jump"))
        return cmd_jump(n, a);
    die("unknown command %s", cmd);
    return 2;
}
