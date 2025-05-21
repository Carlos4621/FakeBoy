#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig LD_addressU16_SP_Config {
        .cartridgePath = "test_LD_addressU16_SP_ROM.gb",
        .minimumTCyclesNeeded = 84,
        .expectedValues = {0xAA, 0xBB, 0xCC, 0xDD}
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_LD_addressU16_SP, LD_addressU16_SP_Config)
DEFINE_BASIC_VALUE_TEST(CPU_LD_addressU16_SP, LD_addressU16_SP_OpcodesWorks)