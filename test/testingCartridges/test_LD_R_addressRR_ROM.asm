SECTION "Header", ROM0[$100]

    nop
    jp Start

    db $CE,$ED,$66,$66,$CC,$0D,$00,$0B
    db $03,$73,$00,$83,$00,$0C,$00,$0D
    db $00,$08,$11,$1F,$88,$89,$00,$0E
    db $DC,$CC,$6E,$E6,$DD,$DD,$D9,$99
    db $BB,$BB,$67,$63,$6E,$0E,$EC,$CC
    db $DD,$DC,$99,$9F,$BB,$B9,$33,$3E

    db "LD R, (RR)",0,0,0,0,0,0

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

    ld a, $bc
    ld [$A000], a
    ld bc, $A000
    ld a, [bc]
    ld [$A009], a

    ld a, $de
    ld [$A001], a
    ld de, $A001
    ld a, [de]
    ld [$A00A], a

    ld a, $ef
    ld [$A002], a
    ld hl, $A002
    ld a, [hl]
    ld [$A00B], a

    ld a, $01
    ld [$A003], a
    ld hl, $A003
    ld b, [hl]
    ld [$A00C], a

    ld a, $02
    ld [$A004], a
    ld hl, $A004
    ld c, [hl]
    ld a, c
    ld [$A00D], a

    ld a, $03
    ld [$A005], a
    ld hl, $A005
    ld d, [hl]
    ld a, d
    ld [$A00E], a

    ld a, $04
    ld [$A006], a
    ld hl, $A006
    ld e, [hl]
    ld a, e
    ld [$A00F], a

    ld a, $05
    ld [$A007], a
    ld hl, $A007
    ld h, [hl]
    ld a, h
    ld [$A010], a

    ld a, $06
    ld [$A008], a
    ld hl, $A008
    ld l, [hl]
    ld a, l
    ld [$A011], a

    jp Start
Loop:
    jr Loop
