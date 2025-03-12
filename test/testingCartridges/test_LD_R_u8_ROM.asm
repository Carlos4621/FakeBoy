INCLUDE "header.asm"

HEADER "LD R, (u8)", MBC_NONE, ROM_32K, RAM_8K

Start:

    ld a, $AA
    ld b, $BB
    ld c, $CC
    ld d, $DD
    ld e, $EE
    ld h, $FE
    ld l, $FF

    ld [$A000], a

    ld a, b
    ld [$A001], a

    ld a, c
    ld [$A002], a

    ld a, d
    ld [$A003], a

    ld a, e
    ld [$A004], a

    ld a, h
    ld [$A005], a

    ld a, l
    ld [$A006], a

    jp Start
