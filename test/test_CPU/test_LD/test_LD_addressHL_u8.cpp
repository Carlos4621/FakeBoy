#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig LD_addressHL_u8_Config {
        .cartridgePath = "test_LD_addressHL_u8_ROM.gb",
        .minimumTCyclesNeeded = 92,
        .expectedValues = {0x01, 0x02, 0x03}
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_LD_addressHL_u8, LD_addressHL_u8_Config)
DEFINE_BASIC_VALUE_TEST(CPU_LD_addressHL_u8, LD_addressHL_u8_OpcodesWorks)