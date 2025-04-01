INCLUDE "header.asm"

HEADER "SBC A, u8", MBC_NONE, ROM_32K, RAM_8K

Start:
    
    ld a, $00
    ld b, $10
    sbc b ; Activar Carry Flag

    ld a, $6
    sbc $4
    ld [$A000], a

    ld a, $FF
    sbc $F0
    ld [$A001], a
