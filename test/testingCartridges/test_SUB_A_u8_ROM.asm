INCLUDE "header.asm"

HEADER "SUB A, u8", MBC_NONE, ROM_32K, RAM_8K

Start:
    
    ld a, $5
    sub $4
    ld [$A000], a

    ld a, $FF
    sub $F0
    ld [$A001], a
