INCLUDE "header.asm"

HEADER "DEC R", MBC_NONE, ROM_32K, RAM_8K

Start:
    ld a, $01
    dec a

    ld b, $02
    dec b

    ld c, $03
    dec c

    ld d, $04
    dec d

    ld e, $05
    dec e

    ld h, $06
    dec h

    ld l, $07
    dec l

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

    ld a, $01
    dec a

    nop

    ld a, $10
    dec a

    jp Start