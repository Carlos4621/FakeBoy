INCLUDE "header.asm"

HEADER "LD A, (C)", MBC_NONE, ROM_32K, RAM_8K

Start:
    ld a, $CC
    ld [$FF80], a

    ld a, $DD
    ld [$FF81], a

    ld a, $00
    ld c, $80
    ld a, [$FF00+c]
    ld [$A000], a

    ld a, $00
    ld c, $81
    ld a, [$FF00+c]
    ld [$A001], a

    jp Start