INCLUDE "header.asm"

HEADER "LD R, (RR)", MBC_NONE, ROM_32K, RAM_8K

Start:

    ld a, $bc
    ld [$A000], a
    ld bc, $A000
    ld a, [bc]
    ld [$A009], a

    ld a, $de
    ld [$A001], a
    ld de, $A001
    ld a, [de]
    ld [$A00A], a

    ld a, $ef
    ld [$A002], a
    ld hl, $A002
    ld a, [hl]
    ld [$A00B], a

    ld a, $01
    ld [$A003], a
    ld hl, $A003
    ld b, [hl]
    ld [$A00C], a

    ld a, $02
    ld [$A004], a
    ld hl, $A004
    ld c, [hl]
    ld a, c
    ld [$A00D], a

    ld a, $03
    ld [$A005], a
    ld hl, $A005
    ld d, [hl]
    ld a, d
    ld [$A00E], a

    ld a, $04
    ld [$A006], a
    ld hl, $A006
    ld e, [hl]
    ld a, e
    ld [$A00F], a

    ld a, $05
    ld [$A007], a
    ld hl, $A007
    ld h, [hl]
    ld a, h
    ld [$A010], a

    ld a, $06
    ld [$A008], a
    ld hl, $A008
    ld l, [hl]
    ld a, l
    ld [$A011], a

    jp Start