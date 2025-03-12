INCLUDE "header.asm"

HEADER "LD (u16), A", MBC_NONE, ROM_32K, RAM_8K

Start:

    ld a, $AA
    ld [$A000], a

    ld a, $BB   
    ld [$A001], a

    ld a, $CC
    ld [$A002], a

    ld a, $DD
    ld [$A003], a

    ld a, $EE
    ld [$A004], a

    ld a, $FE
    ld [$A005], a

    ld a, $FF
    ld [$A006], a

    jp Start