INCLUDE "header.asm"

HEADER "LD SP, HL", MBC_NONE, ROM_32K, RAM_8K

Start:

    ld hl, $BBAA
    ld sp, hl

    ld [$A000], sp

    ld hl, $DDCC
    ld sp, hl

    ld [$A002], sp

    jp Start
