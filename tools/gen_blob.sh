#!/bin/sh
set -e
here=$(cd "$(dirname "$0")/.." && pwd)
cd "$here"
img=${1:-out/ble_hid/ble_hid.plain}
base=16875520
out=blob/blob.bin
runs=$out.runs

[ -f "$img" ] || { echo "tools/gen_blob.sh: no $img: run make patch first" >&2; exit 1; }

awk -v base=$base '
    function h2d(s,   i, v) { v = 0; s = tolower(s)
        for (i = 1; i <= length(s); i++) v = v * 16 + index("0123456789abcdef", substr(s, i, 1)) - 1
        return v }
    /^[ \t]*\.section[ \t]+\.blob\./ {
        a = $2; sub(/.*\.blob\./, "", a); sub(/[^0-9a-fA-F].*/, "", a); at = h2d(a); next
    }
    /^[ \t]*\.incbin/ {
        split($0, f, ",")
        off = f[2] + 0; len = f[3] + 0
        if (have && at == pat + plen && off == poff + plen) { plen += len; next }
        if (have) print pat - base, plen
        have = 1; pat = at; poff = off; plen = len
    }
    END { if (have) print pat - base, plen }
' blob/blob.S > "$runs"

: > "$out"
while read -r skip size; do
    tail -c +$((skip + 1)) "$img" | head -c "$size" >> "$out"
done < "$runs"
echo "$out: $(stat -c%s "$out") bytes from $img, in $(wc -l < "$runs") pieces"
rm -f "$runs"
