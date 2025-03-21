INCLUDE "header.asm"

HEADER "AND A, R", MBC_NONE, ROM_32K, RAM_8K

Start:
    
    ld a, 0b00000001
    ld b, 0b00000001
    and b
    ld [$A000], a

    ld a, 0b00000010
    ld c, 0b00000010
    and c
    ld [$A001], a

    ld a, 0b00000100
    ld d, 0b00000100
    and d
    ld [$A002], a

    ld a, 0b00001000
    ld e, 0b00001000
    and e
    ld [$A003], a

    ld a, 0b00010000
    ld [$A004], a
    ld h, 0b00001000
    and h
    ld [$A004], a

    ld a, 0b00100000
    ld [$A005], a
    ld l, 0b00010000
    and l
    ld [$A005], a

    nop

    ld a, $01
    and a

    ld a, 0b01000000
    ld b, 0b10000000
    and b
    ld [$A006], a

    jp Start