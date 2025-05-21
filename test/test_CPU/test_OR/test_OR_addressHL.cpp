#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig OR_addressHL_Config {
        .cartridgePath = "test_OR_A_addressHL_ROM.gb",
        .minimumTCyclesNeeded = 180,
        .expectedValues = {0b00000011, 0b00000110, 0xFA},
        .flagTests = {
            {
                .description = "Zero Flag Works",
                .additionalCycles = 40,
                .z = true, .h = false, .n = false, .c = false
            }
        }
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_OR_addressHL, OR_addressHL_Config)
DEFINE_BASIC_VALUE_TEST(CPU_OR_addressHL, OR_addressHL_OpcodesWorks)
DEFINE_ALL_FLAG_TESTS(CPU_OR_addressHL, OR_addressHL_FlagsWork)