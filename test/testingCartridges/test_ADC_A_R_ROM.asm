INCLUDE "header.asm"

HEADER "SBC A, R", MBC_NONE, ROM_32K, RAM_8K

Start:

    ; A, A
    ld a, $2
    adc a
    ld [$A000], a

    ld a, $00
    ld b, $10
    sub b ; Activar Carry Flag

    ld a, $3
    adc a
    ld [$A001], a
    adc a

    ; A, B

    ld a, $2
    ld b, $1
    adc b
    ld [$A002], a

    ld a, $00
    ld b, $10
    sub b ; Activar Carry Flag

    ld a, $3
    ld b, $1
    adc b
    ld [$A003], a

    ; A, C
    ld a, $2
    ld c, $1
    adc c
    ld [$A004], a

    ld a, $00
    ld c, $10
    sub c ; Activar Carry Flag

    ld a, $3
    ld c, $1
    adc c
    ld [$A005], a

    ; A, D

    ld a, $2
    ld d, $1
    adc d
    ld [$A006], a

    ld a, $00
    ld d, $10
    sub d ; Activar Carry Flag

    ld a, $3
    ld d, $1
    adc d
    ld [$A007], a

    ; A, E
    ld a, $2
    ld e, $1
    adc e
    ld [$A008], a

    ld a, $00
    ld e, $10
    sub e ; Activar Carry Flag

    ld a, $3
    ld e, $1
    adc e
    ld [$A009], a

    ; A, H

    ld a, $2
    ld h, $1
    adc h
    ld [$A00A], a

    ld a, $00
    ld h, $10
    sub h ; Activar Carry Flag

    ld a, $3
    ld h, $1
    adc h
    ld [$A00B], a

    ; A, L

    ld a, $2
    ld l, $1
    adc l
    ld [$A00C], a

    ld a, $00
    ld l, $10
    sub l ; Activar Carry Flag

    ld a, $3
    ld l, $1
    adc l
    ld [$A00D], a

    nop

    ld a, 0
    ld b, 0
    adc b ; Zero Flag

    nop 

    ld a, $F
    ld b, $01
    adc b ; Half Carry Flag

    nop 

    ld a, $FF
    ld b, $10
    adc b ; Carry Flag

    nop 

    ld a, $8F
    ld b, $77
    adc b ; Carry Flag y Half Carry Flag

    jp Start