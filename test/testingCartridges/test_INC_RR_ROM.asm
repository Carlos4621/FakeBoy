INCLUDE "header.asm"

HEADER "INC RR", MBC_NONE, ROM_32K, RAM_8K

Start:
    ld bc, $9FFF
    inc bc

    ld a, $AA
    ld [bc], a

    ld de, $A000
    inc de

    ld a, $BB
    ld [de], a

    ld hl, $A001
    inc hl

    ld a, $CC
    ld [hl], a

    ld sp, $ABBA
    inc sp

    ld [$A003], sp

    jp Start