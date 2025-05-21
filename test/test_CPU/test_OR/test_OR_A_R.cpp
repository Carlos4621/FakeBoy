#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig OR_A_R_Config {
        .cartridgePath = "test_OR_A_R_ROM.gb",
        .minimumTCyclesNeeded = 268,
        .expectedValues = {0b00000001, 0b00000011, 0b00000110, 0b00001100, 0b00011000, 0},
        .flagTests = {
            {
                .description = "Zero Flag Test",
                .additionalCycles = 36,
                .z = true, .h = false, .n = false, .c = false
            }
        }
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_OR_A_R, OR_A_R_Config)
DEFINE_BASIC_VALUE_TEST(CPU_OR_A_R, OR_A_R_OpcodesWorks)
DEFINE_ALL_FLAG_TESTS(CPU_OR_A_R, OR_A_R_AllFlagsWork)