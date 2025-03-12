INCLUDE "header.asm"

HEADER "LDI LDD (HL), A", MBC_NONE, ROM_32K, RAM_8K

Start:

    ld hl, $A000

    ld a, $AA
    ld [hli], a

    ld a, $BB
    ld [hli], a

    ld hl, $A003

    ld a, $DD
    ld [hld], a

    ld a, $CC
    ld [hld], a

    jp Start
