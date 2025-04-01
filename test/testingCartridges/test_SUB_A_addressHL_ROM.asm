INCLUDE "header.asm"

HEADER "SUB A, (HL)", MBC_NONE, ROM_32K, RAM_8K

Start:
    
    ld a, $6
    ld hl, $A002
    ld [hl], a
    ld a, $9
    sub [hl]
    ld [$A000], a

    ld a, $6
    ld hl, $A002
    ld [hl], a
    ld a, $F
    sub [hl]
    ld [$A001], a
