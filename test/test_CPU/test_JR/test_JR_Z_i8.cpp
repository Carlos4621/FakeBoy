#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig JR_Z_i8_Config {
        .cartridgePath = "test_JR_Z_i8_ROM.gb",
        .minimumTCyclesNeeded = 196,
        .expectedValues = {0x11}
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_JR_Z_i8, JR_Z_i8_Config)
DEFINE_BASIC_VALUE_TEST(CPU_JR_Z_i8, JR_Z_i8_OpcodesWorks)