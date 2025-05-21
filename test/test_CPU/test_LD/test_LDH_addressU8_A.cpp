#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig LDH_addressU8_A_Config {
        .cartridgePath = "test_LDH_addressU8_A_ROM.gb",
        .minimumTCyclesNeeded = 124,
        .expectedValues = {0xAA, 0xBB}
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_LDH_addressU8_A, LDH_addressU8_A_Config)
DEFINE_BASIC_VALUE_TEST(CPU_LDH_addressU8_A, LDH_addressU8_A_OpcodesWorks)