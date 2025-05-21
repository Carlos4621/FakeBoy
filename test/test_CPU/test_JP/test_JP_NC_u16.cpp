#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig JP_NC_u16_Config {
        .cartridgePath = "test_JP_NC_u16_ROM.gb",
        .minimumTCyclesNeeded = 108,
        .expectedValues = {0, 0x99}
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_JP_NC_u16, JP_NC_u16_Config)
DEFINE_BASIC_VALUE_TEST(CPU_JP_NC_u16, JP_NC_u16_OpcodesWorks)