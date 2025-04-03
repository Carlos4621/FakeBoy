INCLUDE "header.asm"

HEADER "JR C, i8", MBC_NONE, ROM_32K, RAM_8K

Start:
    ld a, $FD
    jp loop

loop:
    add a, $1

    jr c, Final
    jp loop

Final:
    ld a, $91
    ld [$A000], a
