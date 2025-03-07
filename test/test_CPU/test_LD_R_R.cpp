#include "Cartridge.hpp"
#include "CPU.hpp"
#include <gtest/gtest.h>
#include <iostream>

static constexpr std::string_view CartidgePath{ "test_LD_R_R_ROM.gb" };
static constexpr uint16_t MinimumTCyclesNeeded{ 1140 };

static constexpr std::array ExpectedValues {
    0xAA, 0xBA, 0xCA, 0xDA,  // A000-A003
    0xEA, 0xFA, 0xFF, 0xBB,  // A004-A007
    0xCB, 0xDB, 0xEB, 0xFB,  // A008-A00B
    0xFF, 0xCC, 0xDC, 0xEC,  // A00C-A00F
    0xFC, 0xFF, 0xDD, 0xED,  // A010-A013
    0xFD, 0xFF, 0xEE, 0xFE,  // A014-A017
    0xFF, 0xFF, 0xFE, 0xFF   // A018-A01B
};

class CPU_LD_R_R_Test : public ::testing::Test {
protected:
    Cartridge cartridge_m{ CartidgePath };
    VideoRAM videoRAM_m;
    WorkingRAM workingRAM_m;
    HighRAM highRAM_m;
    EchoRAM echoRAM_m{ &workingRAM_m };

    MemoryBus memorybus_m{ &cartridge_m, &workingRAM_m, &highRAM_m, &echoRAM_m, &videoRAM_m };

    CPU cpu_m{ &memorybus_m };

    void SetUp() override {
        for (size_t i{ 0 }; i < MinimumTCyclesNeeded; ++i) {
            cpu_m.processTCycle();
        }
     }
};

TEST_F(CPU_LD_R_R_Test, LD_R_R_OpcodesWorks) {
    for (size_t i{ 0 }; i < ExpectedValues.size(); ++i) {
        const auto address{ 0xA000 + i };

        const auto value{ memorybus_m.read(address) };

        EXPECT_EQ(value, ExpectedValues[i]);
    }
}
