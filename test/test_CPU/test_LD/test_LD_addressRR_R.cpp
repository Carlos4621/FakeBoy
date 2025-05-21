#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig LD_addressRR_R_Config {
        .cartridgePath = "test_LD_addressRR_R_ROM.gb",
        .minimumTCyclesNeeded = 292,
        .expectedValues = {0xBC, 0xDE, 0xEF, 0x01, 0x02, 0x03, 0x04, 0xA0, 0x08}
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_LD_addressRR_R, LD_addressRR_R_Config)
DEFINE_BASIC_VALUE_TEST(CPU_LD_addressRR_R, LD_addressRR_R_OpcodesWorks)