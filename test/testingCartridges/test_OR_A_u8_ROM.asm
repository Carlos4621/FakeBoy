INCLUDE "header.asm"

HEADER "OR R, u8", MBC_NONE, ROM_32K, RAM_8K

Start:
    
    ld a, 0b00000001
    ld [$A000], a
    or 0b00000011
    ld [$A000], a

    ld [$A001], a
    ld a, 0b00000010
    or 0b11111101
    ld [$A001], a

    nop 

    ld a, $0
    or $0

    jp Start