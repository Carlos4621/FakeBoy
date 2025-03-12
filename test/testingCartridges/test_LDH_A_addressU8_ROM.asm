INCLUDE "header.asm"

HEADER "LDH A, (u8)", MBC_NONE, ROM_32K, RAM_8K

Start:

    ld a, $AA

    ld [$FF80], a

    ld a, $BB

    ld [$FF81], a

    ldh a, [$FF00+$80]

    ld [$A000], a

    ldh a, [$FF00+$81]

    ld [$A001], a

    jp Start
