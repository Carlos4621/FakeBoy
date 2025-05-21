#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig LD_addressC_A_Config {
        .cartridgePath = "test_LD_addressC_A_ROM.gb",
        .minimumTCyclesNeeded = 140,
        .expectedValues = {0xEE, 0xFF}
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_LD_addressC_A, LD_addressC_A_Config)
DEFINE_BASIC_VALUE_TEST(CPU_LD_addressC_A, LD_addressC_A_OpcodesWorks)