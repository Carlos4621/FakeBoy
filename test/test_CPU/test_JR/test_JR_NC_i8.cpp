#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig JR_NC_i8_Config {
        .cartridgePath = "test_JR_NC_i8_ROM.gb",
        .minimumTCyclesNeeded = 100,
        .expectedValues = {0, 0x43}
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_JR_NC_i8, JR_NC_i8_Config)
DEFINE_BASIC_VALUE_TEST(CPU_JR_NC_i8, JR_NC_i8_OpcodesWorks)