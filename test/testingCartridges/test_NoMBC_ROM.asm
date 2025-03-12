INCLUDE "header.asm"

HEADER "No MBC", MBC_NONE, ROM_32K, RAM_8K

SECTION "TestingBank0Data", ROM0[$3000]
    db $AA, $BB, $CC, $DD

SECTION "TestingSwitchableBankData", ROMX[$7000]
    db $11, $22, $33, $44

Start:
    jp Start