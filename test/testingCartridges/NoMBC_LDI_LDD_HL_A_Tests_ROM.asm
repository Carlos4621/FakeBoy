; main.asm - Ejemplo de header para Game Boy sin MBC y sin RAM By ChatGPT

SECTION "Header", ROM0[$0100]
    ; Punto de entrada (entry point)
    jp Start
    nop
    nop

    ; Logo de Nintendo (48 bytes obligatorios)
    db $CE, $ED, $66, $66, $CC, $0D, $00, $0B
    db $03, $73, $00, $83, $00, $0C, $00, $0D
    db $00, $08, $11, $1F, $88, $89, $00, $0E
    db $DC, $CC, $6E, $E6, $DD, $DD, $D9, $99
    db $BB, $BB, $67, $63, $6E, $0E, $EC, $CC
    db $DD, $DC, $99, $9F, $BB, $B9, $33, $3E

    ; Título del juego (máximo 16 bytes, rellenar con 0 si es necesario)
    db "LDI LDD HL, A"

    ; Datos de fabricante u otros (en este ejemplo se dejan en 0)
    db 0,0,0,0

    ; Campo de Tipo de cartucho (dirección $0147)
    ; 0x00 indica ROM sin MBC
    db $00

    db $00

    ; Campo de Tamaño de ROM (dirección $0148)
    ; 0x00 indica una ROM de 32KB (sin banking)
    db $00

    ; Campo de Tamaño de RAM (dirección $0149)
    ; 0x02 indica que hay RAM externa de 8kb
    db $02

    ; Otros bytes del header (por ejemplo, checksum)
    ; Para este ejemplo se dejan en 0 o se calculan según necesidad
    db 0

Start:

    ld a, $AA
    ld [$A004], a

    ld a, $BB
    ld [$A005], a

    ld a, $DD
    ld [$A006], a

    ld a, $CC
    ld [$A007], a

    ld a, $00
    ld h, $A0
    ld l, $04
    ld a, [hli]

    ld [$A000], a

    ld a, [hli]

    ld [$A001], a

    ld h, $A0
    ld l, $07
    ld a, [hld]

    ld [$A002], a

    ld a, [hld]
    ld [$A003], a

    jp Start
Loop:
    jr Loop
