#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig SBC_A_u8_Config {
        .cartridgePath = "test_SBC_A_u8_ROM.gb",
        .minimumTCyclesNeeded = 104,
        .expectedValues = {1, 0xF}
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_SBC_A_u8, SBC_A_u8_Config)
DEFINE_BASIC_VALUE_TEST(CPU_SBC_A_u8, SBC_A_u8_OpcodesWorks)