INCLUDE "header.asm"

HEADER "LDH (u8), A", MBC_NONE, ROM_32K, RAM_8K

Start:

    ld a, $AA
    ldh [$FF00+$80], a

    ld a, $BB
    ldh [$FF00+$81], a

    ld a, [$FF80]
    ld [$A000], a

    ld a, [$FF81]
    ld [$A001], a

    jp Start
