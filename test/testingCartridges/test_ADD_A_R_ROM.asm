INCLUDE "header.asm"

HEADER "ADD A, R", MBC_NONE, ROM_32K, RAM_8K

Start:
    
    ld a, $0
    ld b, $0
    add b
    ld [$A000], a

    ld a, $1
    ld c, $0
    add c
    ld [$A001], a

    ld a, $2
    ld d, $1
    add d
    ld [$A002], a

    ld a, $3
    ld e, $2
    add e
    ld [$A003], a

    ld a, $4
    ld h, $3
    add h
    ld [$A004], a

    ld a, $5
    ld l, $4
    add l
    ld [$A005], a

    ld a, $F1
    ld b, $0F
    add b
    ld [$A006], a

    nop

    ld a, $0
    ld b, $0
    add b ; Zero Flag

    nop 

    ld a, $0F
    ld b, $1
    add b ; Half Carry Flag

    nop 

    ld a, $F1
    ld b, $10
    add b ; Carry Flag

    nop 

    ld a, $8F
    ld b, $88
    add b ; Carry Flag y Half Carry Flag

    nop 

    ld a, $F1
    ld b, $0F
    add b ; Carry Flag, Zero Flag y Half Carry Flag

    jp Start