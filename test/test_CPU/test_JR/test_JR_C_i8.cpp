#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig JR_C_i8_Config {
        .cartridgePath = "test_JR_C_i8_ROM.gb",
        .minimumTCyclesNeeded = 152,
        .expectedValues = {0x91}
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_JR_C_i8, JR_C_i8_Config)
DEFINE_BASIC_VALUE_TEST(CPU_JR_C_i8, JR_C_i8_OpcodesWorks)