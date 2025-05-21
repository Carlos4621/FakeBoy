#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig SUB_A_u8_Config {
        .cartridgePath = "test_SUB_A_u8_ROM.gb",
        .minimumTCyclesNeeded = 84,
        .expectedValues = {1, 0xF}
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_SUB_A_u8, SUB_A_u8_Config)
DEFINE_BASIC_VALUE_TEST(CPU_SUB_A_u8, SUB_A_u8_OpcodesWorks)