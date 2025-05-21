#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig CALL_u16_Config {
        .cartridgePath = "test_CALL_u16_ROM.gb",
        .minimumTCyclesNeeded = 124,
        .expectedValues = {0x06}
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_CALL_u16, CALL_u16_Config)
DEFINE_BASIC_VALUE_TEST(CPU_CALL_u16, CALL_u16_OpcodesWorks)