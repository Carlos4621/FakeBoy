#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig LD_SP_HL_Config {
        .cartridgePath = "test_LD_SP_HL_ROM.gb",
        .minimumTCyclesNeeded = 100,
        .expectedValues = {0xAA, 0xBB, 0xCC, 0xDD}
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_LD_SP_HL, LD_SP_HL_Config)
DEFINE_BASIC_VALUE_TEST(CPU_LD_SP_HL, LD_SP_HL_OpcodesWorks)