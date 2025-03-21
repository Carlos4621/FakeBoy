INCLUDE "header.asm"

HEADER "AND R, u8", MBC_NONE, ROM_32K, RAM_8K

Start:
    
    ld a, 0b00000001
    ld [$A000], a
    and $0
    ld [$A000], a

    ld [$A001], a
    ld a, 0b00000010
    and 0b00000010
    ld [$A001], a

    nop 

    ld a, 0b00000100
    and $0

    jp Start