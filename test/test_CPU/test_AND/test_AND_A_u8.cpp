#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig AND_A_u8_Config {
        .cartridgePath = "test_AND_A_u8_ROM.gb",
        .minimumTCyclesNeeded = 116,
        .expectedValues = {0, 0b00000010},
        .flagTests = {
            {
                .description = "Zero Flag Test",
                .additionalCycles = 20,
                .z = true, .h = true, .n = false, .c = false
            }
        }
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_AND_A_u8, AND_A_u8_Config)
DEFINE_BASIC_VALUE_TEST(CPU_AND_A_u8, AND_A_u8_OpcodesWorks)
DEFINE_ALL_FLAG_TESTS(CPU_AND_A_u8, AND_A_u8_ZeroFlagWorks)