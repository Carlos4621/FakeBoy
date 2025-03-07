SECTION "Header", ROM0[$100]

    nop
    jp Start

    db $CE,$ED,$66,$66,$CC,$0D,$00,$0B
    db $03,$73,$00,$83,$00,$0C,$00,$0D
    db $00,$08,$11,$1F,$88,$89,$00,$0E
    db $DC,$CC,$6E,$E6,$DD,$DD,$D9,$99
    db $BB,$BB,$67,$63,$6E,$0E,$EC,$CC
    db $DD,$DC,$99,$9F,$BB,$B9,$33,$3E

    db "LD (RR), R",0,0,0,0,0,0

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

    ld b, $A0
    ld c, $00
    ld a, $BC
    ld [bc], a

    ld d, $A0
    ld e, $01
    ld a, $DE
    ld [de], a

    ld h, $A0
    ld l, $02
    ld a, $EF
    ld [hl], a

    ld h, $A0
    ld l, $03
    ld b, $01
    ld [hl], b

    ld h, $A0
    ld l, $04
    ld c, $02
    ld [hl], c

    ld h, $A0
    ld l, $05
    ld d, $03
    ld [hl], d

    ld h, $A0
    ld l, $06
    ld e, $04
    ld [hl], e

    ld h, $A0
    ld l, $07
    ld [hl], h

    ld h, $A0
    ld l, $08
    ld [hl], l

    jp Start
Loop:
    jr Loop
