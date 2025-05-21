#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig INC_addressHL_Config {
        .cartridgePath = "test_INC_addressHL_ROM.gb",
        .minimumTCyclesNeeded = 100,
        .expectedValues = {0x02, 0x03},
        .flagTests = {
            {
                .description = "Increment 0xFF Sets Half And Zero And Unsets Neg",
                .additionalCycles = 44,
                .z = true, .h = true, .n = false, .c = true
            },
            {
                .description = "Increment 0x0F Activate Half And Unsets Neg And Zero",
                .additionalCycles = 88,
                .z = false, .h = true, .n = false, .c = true
            }
        }
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_INC_addressHL, INC_addressHL_Config)
DEFINE_BASIC_VALUE_TEST(CPU_INC_addressHL, INC_addressHL_OpcodesWorks)
DEFINE_ALL_FLAG_TESTS(CPU_INC_addressHL, INC_addressHL_AllFlagsWork)