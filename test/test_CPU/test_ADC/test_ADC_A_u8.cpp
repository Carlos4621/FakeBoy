#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig ADC_A_u8_Config {
        .cartridgePath = "test_ADC_A_u8_ROM.gb",
        .minimumTCyclesNeeded = 104,
        .expectedValues = {11, 0xFF}
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_ADC_A_u8, ADC_A_u8_Config)
DEFINE_BASIC_VALUE_TEST(CPU_ADC_A_u8, ADC_A_u8_OpcodesWorks)