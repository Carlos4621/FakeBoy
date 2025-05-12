#include "Cartridge.hpp"
#include "CPU.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include "TestingCPU.hpp"

static constexpr std::string_view CartidgePath{ "test_POP_RR_ROM.gb" };
static constexpr uint16_t MinimumTCyclesNeeded{ 424 };

static constexpr std::array ExpectedValues {
    0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, 0xF0, 0x1
};

class CPU_POP_RR : public ::testing::Test {
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

TEST_F(CPU_POP_RR, POP_RR_OpcodesWorks) {
    for (size_t i{ 0 }; i < ExpectedValues.size(); ++i) {
        const auto address{ 0xA000 + i };

        const auto value{ memorybus_m.read(address) };

        EXPECT_EQ(value, ExpectedValues[i]);
    }
}