#!/bin/sh
set -e
out=${1:-work}
mkdir -p "$out"
list=$(curl -s -X POST -H "Beta: 1" -H "Type: 30" http://dl.8bitdo.com:8080/firmware/select)
echo "$list" | grep -o '"version":[^,]*,[^}]*"filePathName":"[^"]*"' | while read -r entry; do
    ver=$(echo "$entry" | sed 's/"version":\([0-9.]*\).*/\1/' | awk '{printf "%.2f", $1}')
    path=$(echo "$entry" | sed 's/.*"filePathName":"\([^"]*\)".*/\1/')
    file="$out/zero2_v$ver.dat"
    [ -f "$file" ] || curl -s -o "$file" "http://dl.8bitdo.com:8080$path"
    echo "$file"
done
