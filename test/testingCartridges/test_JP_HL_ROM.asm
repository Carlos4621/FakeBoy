INCLUDE "header.asm"

HEADER "JP HL", MBC_NONE, ROM_32K, RAM_8K

SECTION "Testing", ROM0[$3000]
    ld a, b
    ld [$A000], a

Start:
    ld b, $77
    ld hl, $3000

    jp hl

    jp Start