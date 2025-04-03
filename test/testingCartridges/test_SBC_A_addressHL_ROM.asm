INCLUDE "header.asm"

HEADER "SBC A, (HL)", MBC_NONE, ROM_32K, RAM_8K

Start:
    add a
    ld a, $6
    ld hl, $A002
    ld [hl], a
    ld a, $9
    sbc [hl]
    ld [$A000], a

    ld a, $00
    ld b, $10
    sbc b ; Activar Carry Flag

    ld a, $6
    ld hl, $A002
    ld [hl], a
    ld a, $8
    sbc [hl]
    ld [$A001], a
