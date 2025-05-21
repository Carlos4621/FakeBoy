#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig ADD_HL_RR_Config {
        .cartridgePath = "test_ADD_HL_RR_ROM.gb",
        .minimumTCyclesNeeded = 200,
        .expectedValues = {1, 2, 3, 4},
        .cycleBetweenFlagTests = 36,
        .flagTests = {
            {
                .description = "Zero Flag Test",
                .additionalCycles = 36,
                .z = true, .h = false, .n = false, .c = false
            },
            {
                .description = "Half Carry Flag Test",
                .additionalCycles = 72,
                .z = false, .h = true, .n = false, .c = false
            },
            {
                .description = "Carry Flag Test",
                .additionalCycles = 108,
                .z = false, .h = false, .n = false, .c = true
            },
            {
                .description = "Carry with Half Carry Flag Test",
                .additionalCycles = 144,
                .z = false, .h = true, .n = false, .c = true
            },
            {
                .description = "Carry with Half Carry with Zero Flag Test",
                .additionalCycles = 180,
                .z = true, .h = true, .n = false, .c = true
            }
        }
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_ADD_HL_RR, ADD_HL_RR_Config)
DEFINE_BASIC_VALUE_TEST(CPU_ADD_HL_RR, ADD_HL_RR_OpcodesWorks)
DEFINE_ALL_FLAG_TESTS(CPU_ADD_HL_RR, ADD_HL_RR_AllFlagsWork)