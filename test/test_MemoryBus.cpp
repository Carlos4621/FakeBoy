#include "MemoryBus.hpp"
#include <gtest/gtest.h>
#include "MemoryMap.hpp"

static constexpr std::string_view CartidgePath{ "NoMBC_ROM.gb" };

static constexpr uint8_t Value_Test{ 0x44 };

static constexpr uint16_t CartridgeAddress{ 0x500 };
static constexpr uint16_t HighRAMAddress{ High_RAM_Start_Address + Value_Test };
static constexpr uint16_t WorkingRAMAddress{ Work_RAM_Start_Address + Value_Test };
static constexpr uint16_t EchoRAMAddress{ Echo_RAM_Start_Address + Value_Test };
static constexpr uint16_t VideoRAMAddress{ VRAM_Start_Address + Value_Test };

class MemoryBusTests : public ::testing::Test {
    protected:
        Cartridge cartrige_m{ CartidgePath };
        WorkingRAM workingRam_m{};
        HighRAM highRam_m{};
        EchoRAM echoRam_m{ &workingRam_m };
        VideoRAM videoRam_m{};

        MemoryBus memoryBus_m{ &cartrige_m, &workingRam_m, &highRam_m, &echoRam_m, &videoRam_m };
};

TEST_F(MemoryBusTests, WriteToROMDontWorks){ 
    memoryBus_m.write(CartridgeAddress, Value_Test);

    EXPECT_NE(memoryBus_m.read(CartridgeAddress), Value_Test);
}

TEST_F(MemoryBusTests, WriteReadToHighRAMWorks) {
    memoryBus_m.write(HighRAMAddress, Value_Test);

    EXPECT_EQ(memoryBus_m.read(HighRAMAddress), Value_Test);
    EXPECT_EQ(highRam_m.read(HighRAMAddress), Value_Test);
}

TEST_F(MemoryBusTests, WriteReadToWorkingRAMWorks) {
    memoryBus_m.write(WorkingRAMAddress, Value_Test);

    EXPECT_EQ(memoryBus_m.read(WorkingRAMAddress), Value_Test);
    EXPECT_EQ(workingRam_m.read(WorkingRAMAddress), Value_Test);
}

TEST_F(MemoryBusTests, WriteReadToEchoRAMWorks) {
    memoryBus_m.write(EchoRAMAddress, Value_Test);

    EXPECT_EQ(memoryBus_m.read(EchoRAMAddress), Value_Test);
    EXPECT_EQ(echoRam_m.read(EchoRAMAddress), Value_Test);
    EXPECT_EQ(workingRam_m.read(EchoRAMAddress - 0x1000), Value_Test);
}

TEST_F(MemoryBusTests, WriteReadToVideoRAMWorks) {
    memoryBus_m.write(VideoRAMAddress, Value_Test);

    EXPECT_EQ(memoryBus_m.read(VideoRAMAddress), Value_Test);
    EXPECT_EQ(videoRam_m.read(VideoRAMAddress), Value_Test);
}

TEST_F(MemoryBusTests, ReadFromDisabledRAMReturns0xFF) {
    highRam_m.disable();
    workingRam_m.disable();
    videoRam_m.disable();

    EXPECT_EQ(memoryBus_m.read(HighRAMAddress), 0xFF);
    EXPECT_EQ(memoryBus_m.read(WorkingRAMAddress), 0xFF);
    EXPECT_EQ(memoryBus_m.read(EchoRAMAddress), 0xFF);
    EXPECT_EQ(memoryBus_m.read(VideoRAMAddress), 0xFF);

    highRam_m.enable();
    workingRam_m.enable();
    videoRam_m.enable();
}