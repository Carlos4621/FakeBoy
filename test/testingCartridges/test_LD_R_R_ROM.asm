INCLUDE "header.asm"

HEADER "LD R, R", MBC_NONE, ROM_32K, RAM_8K

Start:

    ; ld A, r
    ld a, $AA
    ld a, a
    ld [$A000], a

    ld a, $BA
    ld b, a
    ld a, $00
    ld a, b
    ld [$A001], a

    ld a, $CA
    ld c, a
    ld a, $00
    ld a, c
    ld [$A002], a

    ld a, $DA
    ld d, a
    ld a, $00
    ld a, d
    ld [$A003], a

    ld a, $EA
    ld e, a
    ld a, $00
    ld a, e
    ld [$A004], a

    ld a, $FA
    ld h, a
    ld a, $00
    ld a, h
    ld [$A005], a

    ld a, $FF
    ld l, a
    ld a, $00
    ld a, l
    ld [$A006], a

    ; ld B, r
    ld b, $BB
    ld b, b
    ld a, b
    ld [$A007], a

    ld b, $CB
    ld c, b
    ld b, $00
    ld b, c
    ld a, b
    ld [$A008], a

    ld b, $DB
    ld d, b
    ld b, $00
    ld b, d
    ld a, b
    ld [$A009], a

    ld b, $EB
    ld e, b
    ld b, $00
    ld b, e
    ld a, b
    ld [$A00A], a

    ld b, $FB
    ld h, b
    ld b, $00
    ld b, h
    ld a, b
    ld [$A00B], a

    ld b, $FF
    ld l, b
    ld b, $00
    ld b, l
    ld a, b
    ld [$A00C], a

    ; ld C, r
    ld c, $CC
    ld c, c
    ld a, c
    ld [$A00D], a

    ld c, $DC
    ld d, c
    ld c, $00
    ld c, d
    ld a, c
    ld [$A00E], a

    ld c, $EC
    ld e, c
    ld c, $00
    ld c, e
    ld a, c
    ld [$A00F], a

    ld c, $FC
    ld h, c
    ld c, $00
    ld c, h
    ld a, c
    ld [$A010], a

    ld c, $FF
    ld l, c
    ld c, $00
    ld c, l
    ld a, c
    ld [$A011], a

    ; ld D, r
    ld d, $DD
    ld d, d
    ld a, d
    ld [$A012], a

    ld d, $ED
    ld e, d
    ld d, $00
    ld d, e
    ld a, d
    ld [$A013], a

    ld d, $FD
    ld h, d
    ld d, $00
    ld d, h
    ld a, d
    ld [$A014], a

    ld d, $FF
    ld l, d
    ld d, $00
    ld d, l
    ld a, d
    ld [$A015], a

    ; ld E, r
    ld e, $EE
    ld e, e
    ld a, e
    ld [$A016], a

    ld e, $FE
    ld h, e
    ld e, $00
    ld e, h
    ld a, e
    ld [$A017], a

    ld e, $FF
    ld l, e
    ld e, $00
    ld e, l
    ld a, e
    ld [$A018], a

    ; ld H, r
    ld h, $FF
    ld h, h
    ld a, h
    ld [$A019], a

    ld h, $FE
    ld l, h
    ld h, $00
    ld h, l
    ld a, h
    ld [$A01A], a

    ; ld L, r
    ld l, $FF
    ld l, l
    ld a, l
    ld [$A01B], a

    jp Start
