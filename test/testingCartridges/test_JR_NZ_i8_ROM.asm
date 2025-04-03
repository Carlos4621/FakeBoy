INCLUDE "header.asm"

HEADER "JR NZ, i8", MBC_NONE, ROM_32K, RAM_8K

Start:
    ld a, 1
    dec a
    jr nz, Unexpected
    
    dec a
    jr nz, Expected

Unexpected:
    ld a, $99
    ld [$A000], a

Expected:
    ld a, $33
    ld [$A001], a

