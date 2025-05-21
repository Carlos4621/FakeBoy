#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig INC_R_Config {
        .cartridgePath = "test_INC_R_ROM.gb",
        .minimumTCyclesNeeded = 240,
        .expectedValues = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07},
        .flagTests = {
            {
                .description = "Increment 0xFF Sets Half And Zero And Unsets Neg",
                .additionalCycles = 16,
                .z = true, .h = true, .n = false, .c = true
            },
            {
                .description = "Increment 0x0F Activate Half And Unsets Neg And Zero",
                .additionalCycles = 32,
                .z = false, .h = true, .n = false, .c = true
            }
        }
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_INC_R, INC_R_Config)
DEFINE_BASIC_VALUE_TEST(CPU_INC_R, INC_R_OpcodesWorks)
DEFINE_ALL_FLAG_TESTS(CPU_INC_R, INC_R_AllFlagsWork)