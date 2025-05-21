#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig DEC_addressHL_Config {
        .cartridgePath = "test_DEC_addressHL_ROM.gb",
        .minimumTCyclesNeeded = 100,
        .expectedValues = {0x02, 0x03},
        .flagTests = {
            {
                .description = "Decrement 0x01 Sets Zero And Neg And Unsets Half",
                .additionalCycles = 44,
                .z = true, .h = false, .n = true, .c = true // Carry al inicio es true
            },
            {
                .description = "Decrement 0x10 Activate Half And Neg And Unsets Zero",
                .additionalCycles = 88,
                .z = false, .h = true, .n = true, .c = true // Carry al inicio es true
            }
        }
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_DEC_addressHL, DEC_addressHL_Config)
DEFINE_BASIC_VALUE_TEST(CPU_DEC_addressHL, DEC_addressHL_OpcodesWorks)
DEFINE_ALL_FLAG_TESTS(CPU_DEC_addressHL, DEC_addressHL_AllFlagsWork)