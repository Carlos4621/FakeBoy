#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig ADD_A_R_Config {
        .cartridgePath = "test_ADD_A_R_ROM.gb",
        .minimumTCyclesNeeded = 272,
        .expectedValues = {0, 1, 3, 5, 7, 9, 0},
        .cycleBetweenFlagTests = 24,
        .flagTests = {
            {
                .description = "Zero Flag Test",
                .additionalCycles = 24,
                .z = true, .h = false, .n = false, .c = false
            },
            {
                .description = "Half Carry Flag Test",
                .additionalCycles = 48,
                .z = false, .h = true, .n = false, .c = false
            },
            {
                .description = "Carry Flag Test",
                .additionalCycles = 72,
                .z = false, .h = false, .n = false, .c = true
            },
            {
                .description = "Carry with Half Carry Flag Test",
                .additionalCycles = 96,
                .z = false, .h = true, .n = false, .c = true
            },
            {
                .description = "Carry with Zero with Half Carry Flag Test",
                .additionalCycles = 120,
                .z = true, .h = true, .n = false, .c = true
            }
        }
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_ADD_A_R, ADD_A_R_Config)
DEFINE_BASIC_VALUE_TEST(CPU_ADD_A_R, ADD_A_R_OpcodesWorks)

DEFINE_ALL_FLAG_TESTS(CPU_ADD_A_R, ADD_A_R_AllFlagsWork)
