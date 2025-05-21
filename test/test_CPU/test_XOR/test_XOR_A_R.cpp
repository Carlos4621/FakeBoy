#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig XOR_A_R_Config {
        .cartridgePath = "test_XOR_A_R_ROM.gb",
        .minimumTCyclesNeeded = 268,
        .expectedValues = {0x1, 0x2, 0x3, 0x4, 0x5, 0x6},
        .flagTests = {
            {
                .description = "Zero Flag Works",
                .additionalCycles = 44,
                .z = true, .h = false, .n = false, .c = false
            }
        }
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_XOR_A_R, XOR_A_R_Config)
DEFINE_BASIC_VALUE_TEST(CPU_XOR_A_R, XOR_A_R_OpcodesWorks)
DEFINE_ALL_FLAG_TESTS(CPU_XOR_A_R, XOR_A_R_AllFlagsWork)