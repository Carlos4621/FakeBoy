INCLUDE "header.asm"

HEADER "AND A, (HL)", MBC_NONE, ROM_32K, RAM_8K

Start:
    
    ld hl, $A003
    ld a, 0b00000001
    ld [hl], a
    and [hl]
    ld [$A000], a

    ld a, 0b00000100
    ld hl, $A004
    ld [hl], a
    and [hl]
    ld [$A001], a

    ld a, $FA
    ld [$A002], a

    nop

    ld a, $0
    ld hl, $A005
    ld [hl], a
    ld a, 0b01001001
    and [hl]

    jp Start