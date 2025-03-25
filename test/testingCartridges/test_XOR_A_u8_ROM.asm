INCLUDE "header.asm"

HEADER "XOR R, u8", MBC_NONE, ROM_32K, RAM_8K

Start:
    
    ld a, 0b00000011
    ld [$A000], a
    xor 0b00000001
    ld [$A000], a

    ld [$A001], a
    ld a, $FF
    xor 0b11111100
    ld [$A001], a

    nop 

    ld a, $0
    xor $0

    jp Start