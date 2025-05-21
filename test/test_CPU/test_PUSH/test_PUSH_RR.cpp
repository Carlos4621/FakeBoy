#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig PUSH_RR_Config {
        .cartridgePath = "test_PUSH_RR_ROM.gb",
        .minimumTCyclesNeeded = 384,
        .expectedValues = {0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, 0xF0, 0xB0}
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_PUSH_RR, PUSH_RR_Config)
DEFINE_BASIC_VALUE_TEST(CPU_PUSH_RR, PUSH_RR_OpcodesWorks)