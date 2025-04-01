INCLUDE "header.asm"

HEADER "SUB A, R", MBC_NONE, ROM_32K, RAM_8K

Start:
    
    ld a, $0
    ld b, $0
    sub b
    ld [$A000], a

    ld a, $5
    ld c, $4
    sub c
    ld [$A001], a

    ld a, $7
    ld d, $4
    sub d
    ld [$A002], a

    ld a, $9
    ld e, $4
    sub e
    ld [$A003], a

    ld a, $A
    ld h, $3
    sub h
    ld [$A004], a

    ld a, $B
    ld l, $2
    sub l
    ld [$A005], a

    ld a, $10
    ld b, $0F
    sub b
    ld [$A006], a

    nop

    ld a, $FF
    ld b, $FF
    sub b ; Zero Flag

    nop 

    ld a, $10
    ld b, $01
    sub b ; Half Carry Flag

    nop 

    ld a, $00
    ld b, $10
    sub b ; Carry Flag

    nop 

    ld a, $10
    ld b, $21
    sub b ; Carry Flag y Half Carry Flag

    jp Start