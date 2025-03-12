INCLUDE "header.asm"

HEADER "LD (C), A", MBC_NONE, ROM_32K, RAM_8K

Start:

    ld a, $EE
    ld c, $80
    ld [$FF00+c], a
    
    ld a, $FF
    ld c, $81
    ld [$FF00+c], a

    ld a, $00
    ld a, [$FF80]
    ld [$A000], a

    ld a, [$FF81]
    ld [$A001], a

    jp Start
Loop:
    jr Loop
