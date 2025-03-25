INCLUDE "header.asm"

HEADER "ADD A, (HL)", MBC_NONE, ROM_32K, RAM_8K

Start:
    
    ld a, $1
    ld hl, $A002
    ld [hl], a
    ld a, $2
    add [hl]
    ld [$A000], a

    ld a, $4
    ld hl, $A002
    ld [hl], a
    ld a, $5
    add [hl]
    ld [$A001], a
