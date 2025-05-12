INCLUDE "header.asm"

HEADER "POP RR", MBC_NONE, ROM_32K, RAM_8K

Start:
    ld bc, $AABB
    push bc
    ld bc, $0000
    pop bc
    ld a, b
    ld [$A000], a ; $AA
    ld a, c
    ld [$A001], a ; $BB

    ld de, $CCDD
    push de
    ld de, $0000
    pop de
    ld a, d
    ld [$A002], a ; $CC
    ld a, e
    ld [$A003], a ; $DD

    ld hl, $EEFF
    push hl
    ld hl, $0000
    pop hl
    ld a, h
    ld [$A004], a ; $EE
    ld a, l
    ld [$A005], a ; $FF

    ; Guarda valores iniciales con flags específicas
    ld a, $F0
    ld b, $DD
    add b      ; Establece carry flag
    ld a, $F0
    push af
    ld a, 0
    add a         ; Resetea las flags
    
    ; Recupera A y F
    pop af
    ld [$A006], a ; Guarda A para verificar ($F0)
    
    ; Guarda el valor de las flags para verificar
    ld a, 0
    jr c, .carry_set
    jr .continue
    .carry_set:
    ld a, 1
    .continue:
    ld [$A007], a ; Guarda 1 si carry está establecido, 0 en caso contrario
    
