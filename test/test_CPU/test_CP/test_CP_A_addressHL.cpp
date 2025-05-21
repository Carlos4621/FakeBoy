#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig CP_A_addressHL_Config {
        .cartridgePath = "test_CP_A_addressHL_ROM.gb",
        .minimumTCyclesNeeded = 140,
        .expectedValues = {9, 0xF}
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_CP_A_addressHL, CP_A_addressHL_Config)
DEFINE_BASIC_VALUE_TEST(CPU_CP_A_addressHL, CP_A_addressHL_OpcodesWorks)