#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig SBC_A_addressHL_Config {
        .cartridgePath = "test_SBC_A_addressHL_ROM.gb",
        .minimumTCyclesNeeded = 164,
        .expectedValues = {3, 1}
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_SBC_A_addressHL, SBC_A_addressHL_Config)
DEFINE_BASIC_VALUE_TEST(CPU_SBC_A_addressHL, SBC_A_addressHL_OpcodesWorks)