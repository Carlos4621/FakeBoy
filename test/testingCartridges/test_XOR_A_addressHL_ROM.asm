INCLUDE "header.asm"

HEADER "XOR A, (HL)", MBC_NONE, ROM_32K, RAM_8K

Start:

    ld a, $FF
    ld [$A003], a
    ld hl, $A003
    ld a, 0b11111110
    xor [hl]
    ld [$A000], a

    ld a, 0b01000011
    ld [$A004], a
    ld hl, $A004
    ld a, 0b01000001
    xor [hl]
    ld [$A001], a

    ld a, $FA
    ld [$A002], a

    nop

    ld a, $0
    ld hl, $A005
    ld [hl], a
    xor [hl]

    jp Start