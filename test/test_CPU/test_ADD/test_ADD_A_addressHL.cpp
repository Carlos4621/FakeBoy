#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig ADD_A_addressHL_Config {
        .cartridgePath = "test_ADD_A_addressHL_ROM.gb",
        .minimumTCyclesNeeded = 140,
        .expectedValues = {3, 9}
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_ADD_A_addressHL, ADD_A_addressHL_Config)
DEFINE_BASIC_VALUE_TEST(CPU_ADD_A_addressHL, ADD_A_addressHL_OpcodesWorks)