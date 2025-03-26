INCLUDE "header.asm"

HEADER "ADD HL, RR", MBC_NONE, ROM_32K, RAM_8K

Start:
    
    ld bc, $0005
    ld hl, $9FFB
    add hl, bc
    ld a, $01
    ld [hl], a

    ld de, $0100
    ld hl, $9F01
    add hl, de
    ld a, $02
    ld [hl], a

    ld hl, $5001
    add hl, hl
    ld a, $03
    ld [hl], a

    ld sp, $0101
    ld hl, $9F02
    add hl, sp
    ld a, $04
    ld [hl], a

    nop

    ld hl, $0
    ld bc, $0
    add hl, bc ; Zero Flag

    nop 

    ld hl, $0FFF
    ld de, $0001
    add hl, de ; Half Carry Flag

    nop 

    ld hl, $8000
    ld bc, $8001
    add hl, bc ; Carry Flag

    nop 

    ld hl, $7800
    ld de, $8801
    add hl, de ; Carry Flag y Half Carry Flag

    nop 

    ld hl, $FFFF
    ld bc, $0001
    add hl, bc ; Carry Flag, Zero Flag y Half Carry Flag

    jp Start