#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig POP_RR_Config {
        .cartridgePath = "test_POP_RR_ROM.gb",
        .minimumTCyclesNeeded = 424,
        .expectedValues = {0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, 0xF0, 0x1}
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_POP_RR, POP_RR_Config)
DEFINE_BASIC_VALUE_TEST(CPU_POP_RR, POP_RR_OpcodesWorks)