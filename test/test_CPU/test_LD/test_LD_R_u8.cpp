#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig LD_R_u8_Config {
        .cartridgePath = "test_LD_R_u8_ROM.gb",
        .minimumTCyclesNeeded = 212,
        .expectedValues = {0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFE, 0xFF}
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_LD_R_u8, LD_R_u8_Config)
DEFINE_BASIC_VALUE_TEST(CPU_LD_R_u8, LD_R_u8_OpcodesWorks)