SECTION "Header", ROM0[$100]

    nop
    jp Start

    db $CE,$ED,$66,$66,$CC,$0D,$00,$0B
    db $03,$73,$00,$83,$00,$0C,$00,$0D
    db $00,$08,$11,$1F,$88,$89,$00,$0E
    db $DC,$CC,$6E,$E6,$DD,$DD,$D9,$99
    db $BB,$BB,$67,$63,$6E,$0E,$EC,$CC
    db $DD,$DC,$99,$9F,$BB,$B9,$33,$3E

    db "LD A, (C)",0,0,0,0,0,0,0

    db "00"

    db $00  

    db $00 ; Tipo de MBC

    db $00 ; Tamaño de la ROM

    db $02 ; Tamaño de la RAM

    db $01

    db $00

    db $00  

    db $00  

    dw $0000  

Start:

    ld a, $CC
    ld [$FF80], a

    ld a, $DD
    ld [$FF81], a

    ld a, $00
    ld c, $80
    ld a, [$FF00+c]
    ld [$A000], a

    ld a, $00
    ld c, $81
    ld a, [$FF00+c]
    ld [$A001], a

    jp Start
Loop:
    jr Loop
