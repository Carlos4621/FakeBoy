#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig JP_HL_Config {
        .cartridgePath = "test_JP_HL_ROM.gb",
        .minimumTCyclesNeeded = 64,
        .expectedValues = {0x77}
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_JP_HL, JP_HL_Config)
DEFINE_BASIC_VALUE_TEST(CPU_JP_HL, JP_HL_OpcodesWorks)