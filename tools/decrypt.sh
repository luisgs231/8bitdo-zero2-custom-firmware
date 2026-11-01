#!/bin/sh
set -e
here=$(cd "$(dirname "$0")/.." && pwd)
cd "$here"
out=firmware/decrypted
zero2=${ZERO2:-build/zero2}
[ -x "$zero2" ] || { echo "tools/decrypt.sh: no $zero2: run make tools first" >&2; exit 1; }
mkdir -p "$out"
for dat in firmware/official/*.dat; do
    name=$(basename "$dat" .dat)
    for s in 0 1; do
        "$zero2" decrypt "$dat" -s $s -o "$out/$name.s$s.bin" 2>&1 | tail -1
    done
done
