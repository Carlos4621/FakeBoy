#include "Cartridge.hpp"
#include "CPU.hpp"
#include <gtest/gtest.h>
#include <iostream>

static constexpr std::string_view CartidgePath{ "test_INC_R_ROM.gb" };
static constexpr uint16_t MinimumTCyclesNeeded{ 240 };

static constexpr std::array ExpectedValues {
    0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07
};

class CPU_INC_R : public ::testing::Test {
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

TEST_F(CPU_INC_R, INC_R_OpcodesWorks) {
    for (size_t i{ 0 }; i < ExpectedValues.size(); ++i) {
        const auto address{ 0xA000 + i };

        const auto value{ memorybus_m.read(address) };

        EXPECT_EQ(value, ExpectedValues[i]);
    }
}
