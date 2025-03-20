INCLUDE "header.asm"

HEADER "INC (HL)", MBC_NONE, ROM_32K, RAM_8K

Start:
    ld a, $01
    ld hl, $A000
    ld [hl], a
    inc [hl]

    ld a, $02
    ld hl, $A001
    ld [hl], a
    inc [hl]

    nop

    ld a, $FF
    ld hl, $A002
    ld [hl], a
    inc [hl]

    nop 

    ld a, $0F
    ld hl, $A003
    ld [hl], a
    inc [hl]

    jp Start