INCLUDE "header.asm"

HEADER "OR A, R", MBC_NONE, ROM_32K, RAM_8K

Start:
    
    ld a, $0
    ld b, 0b00000001
    or b
    ld [$A000], a

    ld a, 0b00000001
    ld c, 0b00000010
    or c
    ld [$A001], a

    ld a, 0b00000010
    ld d, 0b00000100
    or d
    ld [$A002], a

    ld a, 0b00000100
    ld e, 0b00001000
    or e
    ld [$A003], a

    ld a, 0b00001000
    ld [$A004], a
    ld h, 0b00010000
    or h
    ld [$A004], a

    ld a, $0
    ld [$A005], a
    ld l, $0
    or l
    ld [$A005], a

    nop

    ld a, $01
    or a

    ld a, $0
    ld b, $0
    or b
    ld [$A006], a

    jp Start