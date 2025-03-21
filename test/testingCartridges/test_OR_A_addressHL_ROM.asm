INCLUDE "header.asm"

HEADER "OR A, (HL)", MBC_NONE, ROM_32K, RAM_8K

Start:

    ld a, 0b00000010
    ld [$A003], a
    ld hl, $A003
    ld a, 0b00000001
    or [hl]
    ld [$A000], a

    ld a, 0b00000010
    ld [$A004], a
    ld hl, $A004
    ld a, 0b00000100
    or [hl]
    ld [$A001], a

    ld a, $FA
    ld [$A002], a

    nop

    ld a, $0
    ld hl, $A005
    ld [hl], a
    or [hl]

    jp Start