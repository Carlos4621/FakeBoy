#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig OR_A_u8_Config {
        .cartridgePath = "test_OR_A_u8_ROM.gb",
        .minimumTCyclesNeeded = 116,
        .expectedValues = {0b00000011, 0b11111111},
        .flagTests = {
            {
                .description = "Zero Flag Works",
                .additionalCycles = 20,
                .z = true, .h = false, .n = false, .c = false
            }
        }
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_OR_A_u8, OR_A_u8_Config)
DEFINE_BASIC_VALUE_TEST(CPU_OR_A_u8, OR_A_u8_OpcodesWorks)
DEFINE_ALL_FLAG_TESTS(CPU_OR_A_u8, OR_A_u8_AllFlagsWork)