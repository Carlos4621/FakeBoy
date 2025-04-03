INCLUDE "header.asm"

HEADER "JR Z, i8", MBC_NONE, ROM_32K, RAM_8K

Start:
    ld a, 5
    jp loop

loop:
    dec a

    jr z, Final
    jp loop

Final:
    ld a, $11
    ld [$A000], a
