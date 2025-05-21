#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig LDH_A_addressU8_Config {
        .cartridgePath = "test_LDH_A_addressU8_ROM.gb",
        .minimumTCyclesNeeded = 124,
        .expectedValues = {0xAA, 0xBB}
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_LDH_A_addressU8, LDH_A_addressU8_Config)
DEFINE_BASIC_VALUE_TEST(CPU_LDH_A_addressU8, LDH_A_addressU8_OpcodesWorks)