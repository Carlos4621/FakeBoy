INCLUDE "header.asm"

HEADER "LD RR, (u16)", MBC_NONE, ROM_32K, RAM_8K

Start:

    ld bc, $A000
    ld de, $A001
    ld hl, $A002

    ld a, $AA
    ld [bc], a

    ld a, $BB
    ld [de], a

    ld a, $CC
    ld [hl], a

    jp Start
    