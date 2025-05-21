#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig LD_A_addressU16_Config {
        .cartridgePath = "test_LD_A_addressU16_ROM.gb",
        .minimumTCyclesNeeded = 212,
        .expectedValues = {0xAA, 0xBB, 0xCC}
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_LD_A_addressU16, LD_A_addressU16_Config)
DEFINE_BASIC_VALUE_TEST(CPU_LD_A_addressU16, LD_A_addressU16_OpcodesWorks)