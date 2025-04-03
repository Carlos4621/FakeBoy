INCLUDE "header.asm"

HEADER "ADC A, u8", MBC_NONE, ROM_32K, RAM_8K

Start:
    
    ld a, $00
    ld b, $10
    sub b ; Activar Carry Flag

    ld a, $6
    adc $4
    ld [$A000], a

    ld a, $0F
    adc $F0
    ld [$A001], a
