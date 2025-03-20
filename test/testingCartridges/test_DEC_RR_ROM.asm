INCLUDE "header.asm"

HEADER "DEC RR", MBC_NONE, ROM_32K, RAM_8K

Start:
    ld bc, $A001
    dec bc

    ld a, $AA
    ld [bc], a

    ld de, $A002
    dec de

    ld a, $BB
    ld [de], a

    ld hl, $A003
    dec hl

    ld a, $CC
    ld [hl], a

    ld sp, $ABBC
    dec sp

    ld [$A003], sp

    jp Start