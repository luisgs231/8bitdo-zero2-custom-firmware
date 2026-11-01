#!/bin/sh
set -e
here=$(cd "$(dirname "$0")" && pwd)
ghidra=${GHIDRA_HOME:-$HOME/opt/ghidra_12.2_PUBLIC}
bin=${1:-$here/../firmware/decrypted/zero2_v1.08.s1.bin}
name=$(basename "$bin" .bin)
# Ghidra 12.2 refuses a project path with a dot element, and the project is scratch anyway, so it
# goes to the RAM disk and is lost on reboot. The export under out/ is what is kept.
proj=${GHIDRA_PROJECTS:-${XDG_RUNTIME_DIR:-$HOME}/zero2/ghidra}
mkdir -p "$proj"
"$ghidra/support/analyzeHeadless" "$proj" zero2 -overwrite -import "$bin" \
    -loader BinaryLoader -loader-baseAddr 0x01018000 -processor ARM:LE:32:Cortex \
    -scriptPath "$here/ghidra_scripts" -preScript YcSetup.java \
    -postScript YcSeed.java \
    -postScript YcNames.java "$here/names.txt" \
    -postScript YcExport.java "$here/out/$name" > "$proj/$name.log" 2>&1
tail -3 "$proj/$name.log"
