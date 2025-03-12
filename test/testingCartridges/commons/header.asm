def MBC_NONE EQU $00
def MBC1     EQU $01

def ROM_32K   EQU $00

def RAM_NONE  EQU $00
def RAM_8K    EQU $02

MACRO CART_NAME
    db STRSUB("\1", 1, 16)
    REPT 16 - STRLEN(STRSUB("\1", 1, 16))
        db 0
    ENDR
ENDM

MACRO HEADER
    IF _NARG != 4
        FAIL "Error: La macro HEADER requiere exactamente 4 parámetros: título, MBC, tamaño ROM y tamaño RAM"
    ENDC
    
    SECTION "Header", ROM0[$100]

    nop
    jp Start

    ; Logo de Nintendo (obligatorio)
    db $CE,$ED,$66,$66,$CC,$0D,$00,$0B
    db $03,$73,$00,$83,$00,$0C,$00,$0D
    db $00,$08,$11,$1F,$88,$89,$00,$0E
    db $DC,$CC,$6E,$E6,$DD,$DD,$D9,$99
    db $BB,$BB,$67,$63,$6E,$0E,$EC,$CC
    db $DD,$DC,$99,$9F,$BB,$B9,$33,$3E

    CART_NAME \1

    db "00"

    db $00  

    db \2
    db \3
    db \4

    db $01
    db $00
    db $00  
    db $00  
    dw $0000
ENDM