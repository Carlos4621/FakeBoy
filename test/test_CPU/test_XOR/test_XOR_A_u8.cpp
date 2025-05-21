#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig XOR_A_u8_Config {
        .cartridgePath = "test_XOR_A_u8_ROM.gb",
        .minimumTCyclesNeeded = 116,
        .expectedValues = {0x2, 0x3},
        .flagTests = {
            {
                .description = "Zero Flag Works",
                .additionalCycles = 20,
                .z = true, .h = false, .n = false, .c = false
            }
        }
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_XOR_A_u8, XOR_A_u8_Config)
DEFINE_BASIC_VALUE_TEST(CPU_XOR_A_u8, XOR_A_u8_OpcodesWorks)
DEFINE_ALL_FLAG_TESTS(CPU_XOR_A_u8, XOR_A_u8_AllFlagsWork)