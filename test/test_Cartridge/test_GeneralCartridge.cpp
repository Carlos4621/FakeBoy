#include "Cartridge.hpp"
#include <gtest/gtest.h>

static constexpr std::string_view CartidgePath{ "test_NoMBC_NoRAM_ROM.gb" };
static constexpr std::string_view InexistentCartridgePath{ "inexxxistent.gb" };

static constexpr uint8_t Expected_Bank_0_0x3000_Value{ 0xAA };
static constexpr uint8_t Expected_Bank_0_0x3001_Value{ 0xBB };
static constexpr uint8_t Expected_Bank_0_0x3002_Value{ 0xCC };
static constexpr uint8_t Expected_Bank_0_0x3003_Value{ 0xDD };

class Bank_0_ReadValuesTest : public ::testing::Test, public ::testing::WithParamInterface<std::tuple<uint16_t, uint8_t, uint16_t> > {
protected:
    Cartridge cartridge_m{ CartidgePath };
};

class TryToWriteOnROMBank_0_fails : public ::testing::Test, public ::testing::WithParamInterface<std::tuple<uint16_t, uint8_t> > {
protected:
    Cartridge cartridge_m{ CartidgePath };
};

TEST(Cartridge, LoadInexistentCartridgeThrows) {
    EXPECT_THROW(Cartridge{InexistentCartridgePath}, std::runtime_error);
}

TEST(Cartridge, ReadingInvalidAddressThrows) {
    Cartridge cartridge{ CartidgePath };

    EXPECT_THROW(static_cast<void>(cartridge.read(0xFFFF)), std::out_of_range);
}

TEST_P(Bank_0_ReadValuesTest, Bank_0_ReadValuesWorks) {
    const auto [toReadAddress, expectedValue, unexpectedReadAddress] = GetParam();

    EXPECT_EQ(cartridge_m.read(toReadAddress), expectedValue);
    EXPECT_NE(cartridge_m.read(unexpectedReadAddress), expectedValue);
}

TEST_P(TryToWriteOnROMBank_0_fails, TryToWriteOnROMBank_0_fails) {
    const auto [toWriteAddress, value] = GetParam();

    cartridge_m.write(toWriteAddress, value);

    EXPECT_NE(cartridge_m.read(toWriteAddress), value);
}

INSTANTIATE_TEST_SUITE_P(Bank_0_ReadValues, Bank_0_ReadValuesTest, ::testing::Values(
    std::make_tuple(0x3000, Expected_Bank_0_0x3000_Value, 0x3001),
    std::make_tuple(0x3001, Expected_Bank_0_0x3001_Value, 0x3000),
    std::make_tuple(0x3002, Expected_Bank_0_0x3002_Value, 0x3001),
    std::make_tuple(0x3003, Expected_Bank_0_0x3003_Value, 0x3002)
));

INSTANTIATE_TEST_SUITE_P(TryToWriteOnROMBank_0_fails, TryToWriteOnROMBank_0_fails, ::testing::Values(
    std::make_tuple(0x3000, Expected_Bank_0_0x3001_Value),
    std::make_tuple(0x3001, Expected_Bank_0_0x3000_Value),
    std::make_tuple(0x3002, Expected_Bank_0_0x3003_Value),
    std::make_tuple(0x3003, Expected_Bank_0_0x3002_Value)
));
