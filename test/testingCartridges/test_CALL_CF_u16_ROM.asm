INCLUDE "header.asm"

HEADER "CALL CF, u16", MBC_NONE, ROM_32K, RAM_8K

; Direcciones RAM para almacenar resultados
def RAM_RESULTS_START   EQU $A000      ; RAM externa comienza en $A000
def RAM_NZ_TRUE         EQU RAM_RESULTS_START
def RAM_NZ_FALSE        EQU RAM_RESULTS_START + 1
def RAM_Z_TRUE          EQU RAM_RESULTS_START + 2
def RAM_Z_FALSE         EQU RAM_RESULTS_START + 3
def RAM_NC_TRUE         EQU RAM_RESULTS_START + 4
def RAM_NC_FALSE        EQU RAM_RESULTS_START + 5
def RAM_C_TRUE          EQU RAM_RESULTS_START + 6
def RAM_C_FALSE         EQU RAM_RESULTS_START + 7

; Valores para indicar si la llamada fue realizada
def CALL_EXECUTED       EQU $55        ; Indica que CALL se ejecutó
def CALL_SKIPPED        EQU $AA        ; Indica que CALL se omitió
def INITIAL_VALUE       EQU $01        ; Valor inicial en RAM

Start:
    ; Inicializar RAM con valores iniciales
    ld hl, RAM_RESULTS_START
    ld b, 8                        ; 8 resultados para almacenar
    ld a, INITIAL_VALUE
.init_ram_loop:
    ld [hl+], a
    dec b
    jr nz, .init_ram_loop

    ; ---------------------------------------
    ; Prueba CALL NZ, u16 (Call if not zero)
    ; ---------------------------------------
    
    ; Caso 1: Flag Z no activo (NZ verdadero) - Debería CALL
    ld a, 1                        ; Cualquier valor distinto de 0
    add 2                           ; Comparar con 2, A≠2, Z=0 (no activado)
    call nz, NZ_True_Routine       ; Debería llamar porque Z=0
    
    ; Caso 2: Flag Z activo (NZ falso) - No debería CALL
    ld a, CALL_SKIPPED
    ld [RAM_NZ_FALSE], a
    xor a                          ; A = 0
    cp 0                           ; Comparar con 0, A=0, Z=1 (activado) adsfadsf
    call nz, NZ_False_Routine      ; No debería llamar porque Z=1

    ; ---------------------------------------
    ; Prueba CALL Z, u16 (Call if zero)
    ; ---------------------------------------
    
    ; Caso 1: Flag Z activo (Z verdadero) - Debería CALL
    xor a                          ; A = 0
    call z, Z_True_Routine         ; Debería llamar porque Z=1
    
    ; Caso 2: Flag Z no activo (Z falso) - No debería CALL
    ld a, CALL_SKIPPED
    ld [RAM_Z_FALSE], a
    ld a, 1                        ; A = 1
    cp 2                           ; Comparar con 2, A≠2, Z=0 (no activado) dsfadsdfads
    call z, Z_False_Routine        ; No debería llamar porque Z=0

    ; ---------------------------------------
    ; Prueba CALL NC, u16 (Call if no carry)
    ; ---------------------------------------
    
    ; Caso 1: Flag C no activo (NC verdadero) - Debería CALL
    xor a                          ; Reset flags, C=0
    call nc, NC_True_Routine       ; Debería llamar porque C=0
    
    ; Caso 2: Flag C activo (NC falso) - No debería CALL
    ld a, CALL_SKIPPED
    ld [RAM_NC_FALSE], a
    ld a, $FF                      ; A = 255
    add a, 1                       ; Suma genera C=1 (255+1=256 desborda)
    call nc, NC_False_Routine      ; No debería llamar porque C=1

    ; ---------------------------------------
    ; Prueba CALL C, u16 (Call if carry)
    ; ---------------------------------------
    
    ; Caso 1: Flag C activo (C verdadero) - Debería CALL
    ld a, $FF                      ; A = 255
    add a, 1                       ; Suma genera C=1 (255+1=256 desborda)
    call c, C_True_Routine         ; Debería llamar porque C=1
    
    ; Caso 2: Flag C no activo (C falso) - No debería CALL
    ld a, CALL_SKIPPED
    ld [RAM_C_FALSE], a
    xor a                          ; Reset flags, C=0
    call c, C_False_Routine        ; No debería llamar porque C=0

    ; Fin de la prueba, bucle infinito
.end:
    jr .end

; ---------------------------------------
; Rutinas para cada caso - Escriben en RAM
; ---------------------------------------

NZ_True_Routine:
    ld a, CALL_EXECUTED
    ld [RAM_NZ_TRUE], a
    ret

NZ_False_Routine:
    ; Si se llega aquí, la prueba falló
    ld a, CALL_EXECUTED
    ld [RAM_NZ_FALSE], a
    ret

Z_True_Routine:
    ld a, CALL_EXECUTED
    ld [RAM_Z_TRUE], a
    ret

Z_False_Routine:
    ; Si se llega aquí, la prueba falló
    ld a, CALL_EXECUTED
    ld [RAM_Z_FALSE], a
    ret

NC_True_Routine:
    ld a, CALL_EXECUTED
    ld [RAM_NC_TRUE], a
    ret

NC_False_Routine:
    ; Si se llega aquí, la prueba falló
    ld a, CALL_EXECUTED
    ld [RAM_NC_FALSE], a
    ret

C_True_Routine:
    ld a, CALL_EXECUTED
    ld [RAM_C_TRUE], a
    ret

C_False_Routine:
    ; Si se llega aquí, la prueba falló
    ld a, CALL_EXECUTED
    ld [RAM_C_FALSE], a
    ret