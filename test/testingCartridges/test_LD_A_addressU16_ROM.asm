INCLUDE "header.asm"

HEADER "LD A, (u16)", MBC_NONE, ROM_32K, RAM_8K

Start:

    ld a, $AA
    ld [$A003], a
    ld a, $00
    ld a, [$A003]
    ld [$A000], a

    ld a, $BB
    ld [$A004], a
    ld a, $00
    ld a, [$A004]
    ld [$A001], a

    ld a, $CC
    ld [$A005], a
    ld a, $00
    ld a, [$A005]
    ld [$A002], a

    jp Start
