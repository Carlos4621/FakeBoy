SECTION "Header", ROM0[$100]

    nop
    jp Start

    db $CE,$ED,$66,$66,$CC,$0D,$00,$0B
    db $03,$73,$00,$83,$00,$0C,$00,$0D
    db $00,$08,$11,$1F,$88,$89,$00,$0E
    db $DC,$CC,$6E,$E6,$DD,$DD,$D9,$99
    db $BB,$BB,$67,$63,$6E,$0E,$EC,$CC
    db $DD,$DC,$99,$9F,$BB,$B9,$33,$3E

    db "No MBC",0,0,0,0,0,0,0,0,0,0

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

SECTION "TestingBank0Data", ROM0[$3000]
    db $AA, $BB, $CC, $DD

SECTION "TestingSwitchableBankData", ROMX[$7000]
    db $11, $22, $33, $44

Start:
    nop
Loop:
    jr Loop
