#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig LD_A_addressC_Config {
        .cartridgePath = "test_LD_A_addressC_ROM.gb",
        .minimumTCyclesNeeded = 148,
        .expectedValues = {0xCC, 0xDD}
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_LD_A_addressC, LD_A_addressC_Config)
DEFINE_BASIC_VALUE_TEST(CPU_LD_A_addressC, LD_A_addressC_OpcodesWorks)