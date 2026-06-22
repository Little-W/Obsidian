#!/bin/bash

########################################
# Config
########################################
INPUT_DIR="bms2"
ARCHIVE="changes.7z"
CHUNK_SIZE=1400
DELAY=0.1
QR_VERSION=20
QR_CORRECT=Q
TEMP_B64="all.b64"
PAD_CHAR="_"
MISSING_LIST="${1:-}"
MISSING_SET=""

prepare_missing_set() {
    if [ -z "$MISSING_LIST" ]; then
        return 0
    fi

    MISSING_SET=$(mktemp)
    awk '
        {
            line = $0
            gsub(/\r/, "", line)
            if (NR == 1) {
                sub(/^\xef\xbb\xbf/, "", line)
            }
            gsub(/^[[:space:]]+|[[:space:]]+$/, "", line)

            if (line == "") {
                next
            }
            if (line !~ /^[0-9]+$/) {
                printf("[!] Invalid missing-list line %d: %s\n", NR, line) > "/dev/stderr"
                bad = 1
                next
            }
            print int(line)
        }
        END { exit bad ? 1 : 0 }
    ' "$MISSING_LIST" | sort -n | uniq > "$MISSING_SET"

    if [ "${PIPESTATUS[0]}" -ne 0 ]; then
        exit 1
    fi
}

should_emit_frame() {
    local frame_index="$1"

    if [ -z "$MISSING_LIST" ]; then
        return 0
    fi

    grep -qx "$frame_index" "$MISSING_SET"
}

if [ -n "$MISSING_LIST" ] && [ ! -f "$MISSING_LIST" ]; then
    echo "[!] Missing list not found: $MISSING_LIST" >&2
    exit 1
fi

prepare_missing_set
trap 'if [ -n "$MISSING_SET" ]; then rm -f "$MISSING_SET"; fi' EXIT

########################################
# 1. Compress directory
########################################
if [ ! -f "$ARCHIVE" ]; then
    echo "[*] Compressing $INPUT_DIR -> $ARCHIVE ..."
    7za a -t7z -mx=9 "$ARCHIVE" "./$INPUT_DIR" >/dev/null
else
    echo "[*] Using existing archive $ARCHIVE"
fi

########################################
# 2. Base64 encode
########################################
if [ ! -f "$TEMP_B64" ]; then
    echo "[*] Encoding $ARCHIVE -> $TEMP_B64 ..."
    base64 "$ARCHIVE" | tr -d '\n' > "$TEMP_B64"
else
    echo "[*] Using existing Base64 $TEMP_B64"
fi

TOTAL_BYTES=$(wc -c < "$TEMP_B64")
TOTAL_CHUNKS=$(( (TOTAL_BYTES + CHUNK_SIZE - 1) / CHUNK_SIZE ))
echo "[*] Total bytes: $TOTAL_BYTES, Total chunks: $TOTAL_CHUNKS"

if [ -n "$MISSING_LIST" ]; then
    echo "[*] Replaying frames from list: $MISSING_LIST"
    echo "[*] Frames requested: $(wc -l < "$MISSING_SET")"
fi

########################################
# 3. Output QR frames
########################################
INDEX=0
EMITTED=0
clear
offset=0

while [ "$offset" -lt "$TOTAL_BYTES" ]; do
    INDEX=$((INDEX + 1))

    if ! should_emit_frame "$INDEX"; then
        offset=$((offset + CHUNK_SIZE))
        continue
    fi

    CHUNK=$(dd if="$TEMP_B64" bs=1 skip="$offset" count="$CHUNK_SIZE" 2>/dev/null)
    CHUNK_LEN=${#CHUNK}
    if [ "$CHUNK_LEN" -lt "$CHUNK_SIZE" ]; then
        PADDING=$(printf "%0.s$PAD_CHAR" $(seq 1 $((CHUNK_SIZE - CHUNK_LEN))))
        CHUNK="${CHUNK}${PADDING}"
    fi

    FRAME=$(printf "%04d/%04d:%s" "$INDEX" "$TOTAL_CHUNKS" "$CHUNK")

    printf "\033[H"
    echo
    echo "======================================"
    echo "FRAME $INDEX / $TOTAL_CHUNKS"
    echo "======================================"
    echo

    echo "$FRAME" | qrencode -t ANSIUTF8 -l "$QR_CORRECT" -v "$QR_VERSION"

    EMITTED=$((EMITTED + 1))
    sleep "$DELAY"
    offset=$((offset + CHUNK_SIZE))
done

echo "[*] Done, emitted frames: $EMITTED"
