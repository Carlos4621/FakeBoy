INCLUDE "header.asm"

HEADER "ADD A, u8", MBC_NONE, ROM_32K, RAM_8K

Start:
    
    ld a, $0
    add $1
    ld [$A000], a

    ld a, $F0
    add $1F
    ld [$A001], a
