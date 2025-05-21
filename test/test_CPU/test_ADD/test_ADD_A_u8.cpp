#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig ADD_A_u8_Config {
        .cartridgePath = "test_ADD_A_u8_ROM.gb",
        .minimumTCyclesNeeded = 84,
        .expectedValues = {1, 0xF}
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_ADD_A_u8, ADD_A_u8_Config)
DEFINE_BASIC_VALUE_TEST(CPU_ADD_A_u8, ADD_A_u8_OpcodesWorks)