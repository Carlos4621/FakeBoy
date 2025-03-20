INCLUDE "header.asm"

HEADER "INC R", MBC_NONE, ROM_32K, RAM_8K

Start:
    ld a, $00
    inc a

    ld b, $01
    inc b

    ld c, $02
    inc c

    ld d, $03
    inc d

    ld e, $04
    inc e

    ld h, $05
    inc h

    ld l, $06
    inc l

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

    nop

    ld a, $FF
    inc a

    nop

    ld a, $0F
    inc a

    jp Start