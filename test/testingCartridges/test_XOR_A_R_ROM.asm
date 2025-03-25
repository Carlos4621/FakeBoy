INCLUDE "header.asm"

HEADER "XOR A, R", MBC_NONE, ROM_32K, RAM_8K

Start:
    
    ld a, $1
    ld b, $0
    xor b
    ld [$A000], a

    ld a, $3
    ld c, $1
    xor c
    ld [$A001], a

    ld a, $7
    ld d, $4
    xor d
    ld [$A002], a

    ld a, $F
    ld e, $B
    xor e
    ld [$A003], a

    ld a, $1F
    ld [$A004], a
    ld h, $1A
    xor h
    ld [$A004], a

    ld a, $3F
    ld [$A005], a
    ld l, $39
    xor l
    ld [$A005], a

    nop

    ld a, $01
    ld b, $0
    xor b

    ld a, $0
    ld b, $0
    xor b
    ld [$A006], a

    jp Start