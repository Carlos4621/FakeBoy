#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig AND_A_R_Config {
        .cartridgePath = "test_AND_A_R_ROM.gb",
        .minimumTCyclesNeeded = 268,
        .expectedValues = {0b00000001, 0b00000010, 0b00000100, 0b00001000, 0, 0},
        .flagTests = {
            {
                .description = "Zero Flag Test",
                .additionalCycles = 36,
                .z = true, .h = true, .n = false, .c = false
            }
        }
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_AND_A_R, AND_A_R_Config)
DEFINE_BASIC_VALUE_TEST(CPU_AND_A_R, AND_A_R_OpcodesWorks)
DEFINE_ALL_FLAG_TESTS(CPU_AND_A_R, AND_A_R_ZeroFlagWorks)