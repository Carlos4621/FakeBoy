#include "TestHeaders.hpp"

namespace {
    const CPUOpCodeTestConfig LD_R_R_Config {
        .cartridgePath = "test_LD_R_R_ROM.gb",
        .minimumTCyclesNeeded = 1140,
        .expectedValues = {
            0xAA, 0xBA, 0xCA, 0xDA,  // A000-A003
            0xEA, 0xFA, 0xFF, 0xBB,  // A004-A007
            0xCB, 0xDB, 0xEB, 0xFB,  // A008-A00B
            0xFF, 0xCC, 0xDC, 0xEC,  // A00C-A00F
            0xFC, 0xFF, 0xDD, 0xED,  // A010-A013
            0xFD, 0xFF, 0xEE, 0xFE,  // A014-A017
            0xFF, 0xFF, 0xFE, 0xFF   // A018-A01B
        }
    };
}

DEFINE_OPCODE_TEST_CLASS(CPU_LD_R_R, LD_R_R_Config)
DEFINE_BASIC_VALUE_TEST(CPU_LD_R_R, LD_R_R_OpcodesWorks)