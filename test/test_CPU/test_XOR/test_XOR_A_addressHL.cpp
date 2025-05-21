#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig XOR_A_addressHL_Config {
        .cartridgePath = "test_XOR_A_addressHL_ROM.gb",
        .minimumTCyclesNeeded = 180,
        .expectedValues = {0x1, 0x2, 0xFA},
        .flagTests = {
            {
                .description = "Zero Flag Works",
                .additionalCycles = 40,
                .z = true, .h = false, .n = false, .c = false
            }
        }
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_XOR_A_addressHL, XOR_A_addressHL_Config)
DEFINE_BASIC_VALUE_TEST(CPU_XOR_A_addressHL, XOR_A_addressHL_OpcodesWorks)
DEFINE_ALL_FLAG_TESTS(CPU_XOR_A_addressHL, XOR_A_addressHL_FlagsWork)