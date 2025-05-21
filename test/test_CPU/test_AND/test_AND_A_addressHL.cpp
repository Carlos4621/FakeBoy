#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig AND_A_addressHL_Config {
        .cartridgePath = "test_AND_A_addressHL_ROM.gb",
        .minimumTCyclesNeeded = 148,
        .expectedValues = {1, 0b00000100, 0xFA},
        .flagTests = {
            {
                .description = "Zero Flag Test",
                .additionalCycles = 48,
                .z = true, .h = true, .n = false, .c = false
            }
        }
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_AND_A_addressHL, AND_A_addressHL_Config)
DEFINE_BASIC_VALUE_TEST(CPU_AND_A_addressHL, AND_A_addressHL_OpcodesWorks)
DEFINE_ALL_FLAG_TESTS(CPU_AND_A_addressHL, AND_A_addressHL_ZeroFlagWorks)