INCLUDE "header.asm"

HEADER "LDI LDD A, (HL)", MBC_NONE, ROM_32K, RAM_8K

Start:

    ld a, $AA
    ld [$A004], a

    ld a, $BB
    ld [$A005], a

    ld a, $DD
    ld [$A006], a

    ld a, $CC
    ld [$A007], a

    ld a, $00
    ld h, $A0
    ld l, $04
    ld a, [hli]

    ld [$A000], a

    ld a, [hli]

    ld [$A001], a

    ld h, $A0
    ld l, $07
    ld a, [hld]

    ld [$A002], a

    ld a, [hld]
    ld [$A003], a

    jp Start
