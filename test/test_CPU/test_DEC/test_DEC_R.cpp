#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig DEC_R_Config {
        .cartridgePath = "test_DEC_R_ROM.gb",
        .minimumTCyclesNeeded = 240,
        .expectedValues = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06},
        .flagTests = {
            {
                .description = "Decrement 0x01 Sets Neg And Zero And Unsets Half",
                .additionalCycles = 16,
                .z = true, .h = false, .n = true, .c = true // Carry al inicio es true
            },
            {
                .description = "Decrement 0x10 Activate Half And Neg And Unsets Zero",
                .additionalCycles = 32,
                .z = false, .h = true, .n = true, .c = true // Carry al inicio es true
            }
        }
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_DEC_R, DEC_R_Config)
DEFINE_BASIC_VALUE_TEST(CPU_DEC_R, DEC_R_OpcodesWorks)
DEFINE_ALL_FLAG_TESTS(CPU_DEC_R, DEC_R_AllFlagsWork)