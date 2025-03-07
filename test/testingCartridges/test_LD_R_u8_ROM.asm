SECTION "Header", ROM0[$100]

    nop
    jp Start

    db $CE,$ED,$66,$66,$CC,$0D,$00,$0B
    db $03,$73,$00,$83,$00,$0C,$00,$0D
    db $00,$08,$11,$1F,$88,$89,$00,$0E
    db $DC,$CC,$6E,$E6,$DD,$DD,$D9,$99
    db $BB,$BB,$67,$63,$6E,$0E,$EC,$CC
    db $DD,$DC,$99,$9F,$BB,$B9,$33,$3E

    db "LD R, u8",0,0,0,0,0,0,0,0

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

    ld a, $AA
    ld b, $BB
    ld c, $CC
    ld d, $DD
    ld e, $EE
    ld h, $FE
    ld l, $FF

    ld [$A000], a

    ld a, b
    ld [$A001], a

    ld a, c
    ld [$A002], a

    ld a, d
    ld [$A003], a

    ld a, e
    ld [$A004], a

    ld a, h
    ld [$A005], a

    ld a, l
    ld [$A006], a

    jp Start
Loop:
    jr Loop
