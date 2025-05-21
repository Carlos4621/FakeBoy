#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig LDI_LDD_HL_A_Config {
        .cartridgePath = "test_LDI_LDD_HL_A_ROM.gb",
        .minimumTCyclesNeeded = 108,
        .expectedValues = {0xAA, 0xBB, 0xCC, 0xDD}
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_LDI_LDD_HL_A, LDI_LDD_HL_A_Config)
DEFINE_BASIC_VALUE_TEST(CPU_LDI_LDD_HL_A, LDI_LDD_HL_A_OpcodesWorks)