INCLUDE "header.asm"

HEADER "LD (HL), u8", MBC_NONE, ROM_32K, RAM_8K

Start:

    ld hl, $A000
    ld [hl], $01

    ld hl, $A001
    ld [hl], $02

    ld hl, $A002
    ld [hl], $03

    jp Start
