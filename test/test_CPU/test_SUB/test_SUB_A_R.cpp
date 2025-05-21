#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig SUB_A_R_Config {
        .cartridgePath = "test_SUB_A_R_ROM.gb",
        .minimumTCyclesNeeded = 272,
        .expectedValues = {0, 1, 3, 5, 7, 9, 1},
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

DEFINE_OPCODE_TEST_CLASS(CPU_SUB_A_R, SUB_A_R_Config)
DEFINE_BASIC_VALUE_TEST(CPU_SUB_A_R, SUB_A_R_OpcodesWorks)
DEFINE_ALL_FLAG_TESTS(CPU_SUB_A_R, SUB_A_R_AllFlagsWork)