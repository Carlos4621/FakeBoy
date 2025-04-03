INCLUDE "header.asm"

HEADER "JR i8", MBC_NONE, ROM_32K, RAM_8K

Start:
    ld a, 0
    jp loop

loop:
    inc a
    ld [$A000], a

    jr loop