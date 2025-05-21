#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig CP_A_R_Config {
        .cartridgePath = "test_CP_A_R_ROM.gb",
        .minimumTCyclesNeeded = 272,
        .expectedValues = {0, 5, 7, 9, 0xA, 0xB, 0x10},
        .flagTests = {
            {
                .description = "Zero Flag Test",
                .additionalCycles = 24,
                .z = true, .h = false, .n = true, .c = false
            },
            {
                .description = "Half Carry Flag Test",
                .additionalCycles = 48,
                .z = false, .h = true, .n = true, .c = false
            },
            {
                .description = "Carry Flag Test",
                .additionalCycles = 72,
                .z = false, .h = false, .n = true, .c = true
            },
            {
                .description = "Carry with Half Carry Flag Test",
                .additionalCycles = 96,
                .z = false, .h = true, .n = true, .c = true
            }
        }
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_CP_A_R, CP_A_R_Config)
DEFINE_BASIC_VALUE_TEST(CPU_CP_A_R, CP_A_R_OpcodesWorks)
DEFINE_ALL_FLAG_TESTS(CPU_CP_A_R, CP_A_R_AllFlagsWork)