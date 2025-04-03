INCLUDE "header.asm"

HEADER "JP NC, HL", MBC_NONE, ROM_32K, RAM_8K

Start:
    ld a, $F0
    add a

    ld b, $33
    jr nc, Unexpected

    ld a, $1
    add a

    ld b, $43
    jr nc, Expected

    jp Start

Expected:
    ld a, b
    ld [$A001], a

Unexpected:
    ld a, b
    ld [$A000], a