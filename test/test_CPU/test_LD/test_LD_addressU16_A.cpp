#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig LD_addressU16_A_Config {
        .cartridgePath = "test_LD_addressU16_A_ROM.gb",
        .minimumTCyclesNeeded = 188,
        .expectedValues = {0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFE, 0xFF}
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_LD_addressU16_A, LD_addressU16_A_Config)
DEFINE_BASIC_VALUE_TEST(CPU_LD_addressU16_A, LD_addressU16_A_OpcodesWorks)