#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig JR_NZ_i8_Config {
        .cartridgePath = "test_JR_NZ_i8_ROM.gb",
        .minimumTCyclesNeeded = 80,
        .expectedValues = {0, 0x33}
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_JR_NZ_i8, JR_NZ_i8_Config)
DEFINE_BASIC_VALUE_TEST(CPU_JR_NZ_i8, JR_NZ_i8_OpcodesWorks)