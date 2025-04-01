INCLUDE "header.asm"

HEADER "CP A, (HL)", MBC_NONE, ROM_32K, RAM_8K

Start:
    
    ld a, $6
    ld hl, $A002
    ld [hl], a
    ld a, $9
    cp [hl]
    ld [$A000], a

    ld a, $6
    ld hl, $A002
    ld [hl], a
    ld a, $F
    cp [hl]
    ld [$A001], a
