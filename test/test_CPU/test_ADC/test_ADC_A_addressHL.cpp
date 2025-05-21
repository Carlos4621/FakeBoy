#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig ADC_A_addressHL_Config {
        .cartridgePath = "test_ADC_A_addressHL_ROM.gb",
        .minimumTCyclesNeeded = 164,
        .expectedValues = {15, 15}
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_ADC_A_addressHL, ADC_A_addressHL_Config)
DEFINE_BASIC_VALUE_TEST(CPU_ADC_A_addressHL, ADC_A_addressHL_OpcodesWorks)