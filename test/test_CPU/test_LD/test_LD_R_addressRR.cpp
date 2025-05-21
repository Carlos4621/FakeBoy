#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig LD_R_addressRR_Config {
        .cartridgePath = "test_LD_R_addressRR_ROM.gb",
        .minimumTCyclesNeeded = 580,
        .expectedValues = {0xBC, 0xDE, 0xEF, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06}
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_LD_R_addressRR, LD_R_addressRR_Config)
DEFINE_BASIC_VALUE_TEST(CPU_LD_R_addressRR, LD_R_addressRR_OpcodesWorks)