#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig INC_RR_Config {
        .cartridgePath = "test_INC_RR_ROM.gb",
        .minimumTCyclesNeeded = 168,
        .expectedValues = {0xAA, 0xBB, 0xCC, 0xBB, 0xAB}
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_INC_RR, INC_RR_Config)
DEFINE_BASIC_VALUE_TEST(CPU_INC_RR, INC_RR_OpcodesWorks)