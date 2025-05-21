#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig LD_RR_u16_Config {
        .cartridgePath = "test_LD_RR_u16_ROM.gb",
        .minimumTCyclesNeeded = 104,
        .expectedValues = {0xAA, 0xBB, 0xCC}
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_LD_RR_u16, LD_RR_u16_Config)
DEFINE_BASIC_VALUE_TEST(CPU_LD_RR_u16, LD_RR_u16_OpcodesWorks)