#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig LDI_LDD_A_HL_Config {
        .cartridgePath = "test_LDI_LDD_A_HL_ROM.gb",
        .minimumTCyclesNeeded = 252,
        .expectedValues = {0xAA, 0xBB, 0xCC, 0xDD}
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_LDI_LDD_A_HL, LDI_LDD_A_HL_Config)
DEFINE_BASIC_VALUE_TEST(CPU_LDI_LDD_A_HL, LDI_LDD_A_HL_OpcodesWorks)