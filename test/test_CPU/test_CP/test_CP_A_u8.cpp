#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig CP_A_u8_Config {
        .cartridgePath = "test_CP_A_u8_ROM.gb",
        .minimumTCyclesNeeded = 84,
        .expectedValues = {5, 0xFF}
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_CP_A_u8, CP_A_u8_Config)
DEFINE_BASIC_VALUE_TEST(CPU_CP_A_u8, CP_A_u8_OpcodesWorks)