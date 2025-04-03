INCLUDE "header.asm"

HEADER "ADC A, (HL)", MBC_NONE, ROM_32K, RAM_8K

Start:

    ld a, $6
    ld hl, $A002
    ld [hl], a
    ld a, $9
    adc [hl]
    ld [$A000], a

    ld a, $00
    ld b, $10
    sub b ; Activar Carry Flag

    ld a, $6
    ld hl, $A002
    ld [hl], a
    ld a, $8
    adc [hl]
    ld [$A001], a
