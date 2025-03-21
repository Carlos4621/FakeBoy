#include "Cartridge.hpp"
#include "CPU.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include "TestingCPU.hpp"

static constexpr std::string_view CartidgePath{ "test_OR_A_addressHL_ROM.gb" };
static constexpr uint16_t MinimumTCyclesNeeded{ 188 };
static constexpr uint8_t TCyclesForOthersSections{ 40 };

static constexpr std::array ExpectedValues {
   0b00000011, 0b00000110, 0xFA
};

class CPU_OR_A_addressHL : public ::testing::Test {
protected:
    Cartridge cartridge_m{ CartidgePath };
    VideoRAM videoRAM_m;
    WorkingRAM workingRAM_m;
    HighRAM highRAM_m;
    EchoRAM echoRAM_m{ &workingRAM_m };

    MemoryBus memorybus_m{ &cartridge_m, &workingRAM_m, &highRAM_m, &echoRAM_m, &videoRAM_m };

    TestingCPU cpu_m{ &memorybus_m };

    void SetUp() override {
        for (size_t i{ 0 }; i < MinimumTCyclesNeeded; ++i) {
            cpu_m.processTCycle();
        }
    }
};

TEST_F(CPU_OR_A_addressHL, OR_A_addressHL_OpcodesWorks) {
    for (size_t i{ 0 }; i < ExpectedValues.size(); ++i) {
        const auto address{ 0xA000 + i };

        const auto value{ memorybus_m.read(address) };

        EXPECT_EQ(value, ExpectedValues[i]);
    }
}

TEST_F(CPU_OR_A_addressHL, OR_A_addressHL_ZeroFlagWorks) {
    for (size_t i{ 0 }; i < TCyclesForOthersSections; ++i) {
        cpu_m.processTCycle();
    }

    EXPECT_EQ(true, cpu_m.getRegisters().getFlag(CPURegisters::Flags::Z));
    EXPECT_EQ(false, cpu_m.getRegisters().getFlag(CPURegisters::Flags::H));
    EXPECT_EQ(false, cpu_m.getRegisters().getFlag(CPURegisters::Flags::N));
    EXPECT_EQ(false, cpu_m.getRegisters().getFlag(CPURegisters::Flags::C));
}