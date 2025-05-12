INCLUDE "header.asm"

HEADER "CALL u16", MBC_NONE, ROM_32K, RAM_8K

Start:
    LD A, $00 ; 8
    LD B, $AA ; 16
    CALL Subrutina ; 40
    CP $AA ;48
    JP NZ, Fallo ; 60
    LD A, $06 ; 68
    LD [$A000], A ; 84

Fallo:
    LD A, $FF
    LD [$A000], A
    jp Fallo

Subrutina:
    LD A, B ; 88 
    POP HL ; 100
    JP HL ; 104
