#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig JR_i8_Config {
        .cartridgePath = "test_JR_i8_ROM.gb",
        .minimumTCyclesNeeded = 192,
        .expectedValues = {5}
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_JR_i8, JR_i8_Config)
DEFINE_BASIC_VALUE_TEST(CPU_JR_i8, JR_i8_OpcodesWorks)