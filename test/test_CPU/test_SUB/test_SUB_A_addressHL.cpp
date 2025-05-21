#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig SUB_A_addressHL_Config {
        .cartridgePath = "test_SUB_A_addressHL_ROM.gb",
        .minimumTCyclesNeeded = 140,
        .expectedValues = {3, 9}
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_SUB_A_addressHL, SUB_A_addressHL_Config)
DEFINE_BASIC_VALUE_TEST(CPU_SUB_A_addressHL, SUB_A_addressHL_OpcodesWorks)