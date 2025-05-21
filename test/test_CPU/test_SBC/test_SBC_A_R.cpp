#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig SBC_A_R_Config {
        .cartridgePath = "test_SBC_A_R_ROM.gb",
        .minimumTCyclesNeeded = 656,
        .expectedValues = {0, 0xFF, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        .flagTests = {
            {
                .description = "Zero Flag Works",
                .additionalCycles = 24,
                .z = true, .h = false, .n = true, .c = false
            },
            {
                .description = "Half Carry Flag Works",
                .additionalCycles = 48,
                .z = false, .h = true, .n = true, .c = false
            },
            {
                .description = "Carry Flag Works",
                .additionalCycles = 72,
                .z = false, .h = false, .n = true, .c = true
            },
            {
                .description = "Carry With Half Carry Flag Works",
                .additionalCycles = 96,
                .z = false, .h = true, .n = true, .c = true
            }
        }
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_SBC_A_R, SBC_A_R_Config)
DEFINE_BASIC_VALUE_TEST(CPU_SBC_A_R, SBC_A_R_OpcodesWorks)
DEFINE_ALL_FLAG_TESTS(CPU_SBC_A_R, SBC_A_R_AllFlagsWork)