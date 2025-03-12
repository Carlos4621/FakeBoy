#include "Cartridge.hpp"
#include <gtest/gtest.h>

static constexpr std::string_view CartidgePath{ "test_NoMBC_ROM.gb" };

static constexpr uint8_t Expected_RAM_0xA000_Value{ 0xAA };
static constexpr uint8_t Expected_RAM_0xA001_Value{ 0xBB };
static constexpr uint8_t Expected_RAM_0xA002_Value{ 0xCC };
static constexpr uint8_t Expected_RAM_0xA003_Value{ 0xDD };

class RAM_ReadWriteValuesTest : public ::testing::Test, public ::testing::WithParamInterface<std::tuple<uint16_t, uint8_t, uint16_t> > {
protected:
    Cartridge cartridge_m{ CartidgePath };
};

TEST(Cartridge, ReadingInvalidRAMAddressThrows) {
    Cartridge cartridge{ CartidgePath };

    EXPECT_THROW(static_cast<void>(cartridge.read(0xFFFF)), std::out_of_range);
}

TEST(Cartridge, WritingInvalidRAMAddressThrows) {
    Cartridge cartridge{ CartidgePath };

    EXPECT_THROW(cartridge.write(0xFFFF, 0x00), std::out_of_range);
}

TEST_P(RAM_ReadWriteValuesTest, RAM_ReadWriteValuesWorks) {
    const auto [toReadAddress, expectedValue, unexpectedReadAddress] = GetParam();

    cartridge_m.write(toReadAddress, expectedValue);

    EXPECT_EQ(cartridge_m.read(toReadAddress), expectedValue);
    EXPECT_NE(cartridge_m.read(unexpectedReadAddress), expectedValue);
}

INSTANTIATE_TEST_SUITE_P(RAM_ReadWriteValues, RAM_ReadWriteValuesTest, ::testing::Values(
    std::make_tuple(0xA000, Expected_RAM_0xA000_Value, 0xA001),
    std::make_tuple(0xA001, Expected_RAM_0xA001_Value, 0xA000),
    std::make_tuple(0xA002, Expected_RAM_0xA002_Value, 0xA001),
    std::make_tuple(0xA003, Expected_RAM_0xA003_Value, 0xA002)
));