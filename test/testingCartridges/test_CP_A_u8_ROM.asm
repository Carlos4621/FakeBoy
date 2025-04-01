INCLUDE "header.asm"

HEADER "CP A, u8", MBC_NONE, ROM_32K, RAM_8K

Start:
    
    ld a, $5
    cp $4
    ld [$A000], a

    ld a, $FF
    cp $F0
    ld [$A001], a
