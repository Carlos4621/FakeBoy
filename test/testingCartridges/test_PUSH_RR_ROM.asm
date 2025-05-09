INCLUDE "header.asm"

HEADER "PUSH RR", MBC_NONE, ROM_32K, RAM_8K

Start:
    ld bc, $AABB
    push bc

    ld a, [$FFFD]
    ld [$A000], a ; $AA

    ld a, [$FFFC]
    ld [$A001], a ; $BB

    ld de, $CCDD
    push de

    ld a, [$FFFB]
    ld [$A002], a ; $CC

    ld a, [$FFFA]
    ld [$A003], a ; $DD

    ld hl, $EEFF
    push hl

    ld a, [$FFF9]
    ld [$A004], a ; $EE

    ld a, [$FFF8]
    ld [$A005], a ; $FF

    ld a, $F0
    push af

    ld a, [$FFF7]
    ld [$A006], a ; $F0
    ld a, [$FFF6]
    ld [$A007], a ; $B0 (flags default)


