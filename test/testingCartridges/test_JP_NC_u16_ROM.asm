INCLUDE "header.asm"

HEADER "JP NC, HL", MBC_NONE, ROM_32K, RAM_8K

SECTION "Expected", ROM0[$3000]
    ld a, b
    ld [$A001], a

SECTION "Unexpected", ROM0[$2000]
    ld a, b
    ld [$A000], a

Start:
    ld a, $F0
    add a

    ld b, $33
    jp nc, $2000

    ld a, $1
    add a

    ld b, $99
    jp nc, $3000

    jp Start