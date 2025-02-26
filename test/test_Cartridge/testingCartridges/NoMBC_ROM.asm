; main.asm - Ejemplo de header para Game Boy sin MBC By ChatGPT

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
    db "TestingROM_1",0

    ; Datos de fabricante u otros (en este ejemplo se dejan en 0)
    db 0,0,0,0

    ; Campo de Tipo de cartucho (dirección $0147)
    ; 0x00 indica ROM sin MBC
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

SECTION "TestingBank0Data", ROM0[$3000]
    db $AA, $BB, $CC, $DD

SECTION "TestingSwitchableBankData", ROMX[$7000]
    db $11, $22, $33, $44

Start:
    nop
Loop:
    jr Loop
