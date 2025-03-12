INCLUDE "header.asm"

HEADER "LD (RR), R", MBC_NONE, ROM_32K, RAM_8K

Start:

    ld b, $A0
    ld c, $00
    ld a, $BC
    ld [bc], a

    ld d, $A0
    ld e, $01
    ld a, $DE
    ld [de], a

    ld h, $A0
    ld l, $02
    ld a, $EF
    ld [hl], a

    ld h, $A0
    ld l, $03
    ld b, $01
    ld [hl], b

    ld h, $A0
    ld l, $04
    ld c, $02
    ld [hl], c

    ld h, $A0
    ld l, $05
    ld d, $03
    ld [hl], d

    ld h, $A0
    ld l, $06
    ld e, $04
    ld [hl], e

    ld h, $A0
    ld l, $07
    ld [hl], h

    ld h, $A0
    ld l, $08
    ld [hl], l

    jp Start
