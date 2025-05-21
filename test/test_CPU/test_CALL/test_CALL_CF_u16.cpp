#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig CALL_CF_u16_Config {
        .cartridgePath = "test_CALL_CF_u16_ROM.gb",
        .minimumTCyclesNeeded = 708,
        .expectedValues = {0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA}
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_CALL_CF_u16, CALL_CF_u16_Config)
DEFINE_BASIC_VALUE_TEST(CPU_CALL_CF_u16, CALL_CF_u16_OpcodesWorks)