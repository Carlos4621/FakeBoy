INCLUDE "header.asm"

HEADER "SBC A, R", MBC_NONE, ROM_32K, RAM_8K

Start:

    ; A, A
    ld a, $2
    sbc a
    ld [$A000], a

    ld a, $00
    ld b, $10
    sbc b ; Activar Carry Flag

    ld a, $3
    sbc a
    ld [$A001], a
    sbc a

    ; A, B

    ld a, $2
    ld b, $1
    sbc b
    ld [$A002], a

    ld a, $00
    ld b, $10
    sbc b ; Activar Carry Flag

    ld a, $3
    ld b, $1
    sbc b
    ld [$A003], a

    ; A, C
    ld a, $2
    ld c, $1
    sbc c
    ld [$A004], a

    ld a, $00
    ld c, $10
    sbc c ; Activar Carry Flag

    ld a, $3
    ld c, $1
    sbc c
    ld [$A005], a

    ; A, D

    ld a, $2
    ld d, $1
    sbc d
    ld [$A006], a

    ld a, $00
    ld d, $10
    sbc d ; Activar Carry Flag

    ld a, $3
    ld d, $1
    sbc d
    ld [$A007], a

     ; A, E

     ld a, $2
     ld e, $1
     sbc e
     ld [$A008], a
 
     ld a, $00
     ld e, $10
     sbc e ; Activar Carry Flag
 
     ld a, $3
     ld e, $1
     sbc e
     ld [$A009], a

    ; A, H

    ld a, $2
    ld h, $1
    sbc h
    ld [$A00A], a

    ld a, $00
    ld h, $10
    sbc h ; Activar Carry Flag

    ld a, $3
    ld h, $1
    sbc h
    ld [$A00B], a

    ; A, L

    ld a, $2
    ld l, $1
    sbc l
    ld [$A00C], a

    ld a, $00
    ld l, $10
    sbc l ; Activar Carry Flag

    ld a, $3
    ld l, $1
    sbc l
    ld [$A00D], a

    nop

    ld a, $FF
    ld b, $FF
    sbc b ; Zero Flag

    nop 

    ld a, $10
    ld b, $01
    sbc b ; Half Carry Flag

    nop 

    ld a, $00
    ld b, $10
    sbc b ; Carry Flag

    nop 

    ld a, $10
    ld b, $21
    sbc b ; Carry Flag y Half Carry Flag

    jp Start