INCLUDE "header.asm"

HEADER "LD (u16), SP", MBC_NONE, ROM_32K, RAM_8K

Start:

    ld sp, $BBAA
    ld [$A000], sp

    ld sp, $DDCC
    ld [$A002], sp

    jp Start
