INCLUDE "header.asm"

HEADER "DEC (HL)", MBC_NONE, ROM_32K, RAM_8K

Start:
    ld a, $03
    ld hl, $A000
    ld [hl], a
    dec [hl]

    ld a, $04
    ld hl, $A001
    ld [hl], a
    dec [hl]

    nop

    ld a, $01
    ld hl, $A002
    ld [hl], a
    dec [hl]

    nop

    ld a, $10
    ld hl, $A003
    ld [hl], a
    dec [hl]

    jp Start