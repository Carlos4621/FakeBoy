#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig DEC_RR_Config {
        .cartridgePath = "test_DEC_RR_ROM.gb",
        .minimumTCyclesNeeded = 168,
        .expectedValues = {0xAA, 0xBB, 0xCC, 0xBB, 0xAB}
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_DEC_RR, DEC_RR_Config)
DEFINE_BASIC_VALUE_TEST(CPU_DEC_RR, DEC_RR_OpcodesWorks)