#include "Cartridge.hpp"
#include <gtest/gtest.h>

static constexpr std::string_view CartidgePath{ "test_NoMBC_NoRAM_ROM.gb" };

static constexpr uint8_t Expected_Bank_1_0x7000_Value{ 0x11 };
static constexpr uint8_t Expected_Bank_1_0x7001_Value{ 0x22 };
static constexpr uint8_t Expected_Bank_1_0x7002_Value{ 0x33 };
static constexpr uint8_t Expected_Bank_1_0x7003_Value{ 0x44 };

static constexpr uint16_t A_RAM_Address{ 0xB000 };

class Bank_1_ReadValuesTest : public ::testing::Test, public ::testing::WithParamInterface<std::tuple<uint16_t, uint8_t, uint16_t> > {
protected:
    Cartridge cartridge_m{ CartidgePath };
};

class TryToWriteOnROMBank_1_fails : public ::testing::Test, public ::testing::WithParamInterface<std::tuple<uint16_t, uint8_t> > {
protected:
    Cartridge cartridge_m{ CartidgePath };
};

TEST(Cartridge, ReadingDisabledRAM_returns0xFF) {
    Cartridge cartridge{ CartidgePath };

    EXPECT_EQ(cartridge.read(A_RAM_Address), 0xFF);
}

TEST(Cartridge, WritingNoRAM_doesNotChangeValue) {
    Cartridge cartridge{ CartidgePath };

    cartridge.write(A_RAM_Address, 0x00);

    EXPECT_EQ(cartridge.read(A_RAM_Address), 0xFF);
}

TEST_P(Bank_1_ReadValuesTest, Bank_1_ReadValuesWorks) {
    const auto [toReadAddress, expectedValue, unexpectedReadAddress] = GetParam();

    EXPECT_EQ(cartridge_m.read(toReadAddress), expectedValue);
    EXPECT_NE(cartridge_m.read(unexpectedReadAddress), expectedValue);
}

TEST_P(TryToWriteOnROMBank_1_fails, TryToWriteOnROMBank_1_fails) {
    const auto [toWriteAddress, value] = GetParam();

    cartridge_m.write(toWriteAddress, value);

    EXPECT_NE(cartridge_m.read(toWriteAddress), value);
}

INSTANTIATE_TEST_SUITE_P(Bank_1_ReadValues, Bank_1_ReadValuesTest, ::testing::Values(
    std::make_tuple(0x7000, Expected_Bank_1_0x7000_Value, 0x7001),
    std::make_tuple(0x7001, Expected_Bank_1_0x7001_Value, 0x7000),
    std::make_tuple(0x7002, Expected_Bank_1_0x7002_Value, 0x7001),
    std::make_tuple(0x7003, Expected_Bank_1_0x7003_Value, 0x7002)
));

INSTANTIATE_TEST_SUITE_P(TryToWriteOnROMBank_1_fails, TryToWriteOnROMBank_1_fails, ::testing::Values(
    std::make_tuple(0x7000, Expected_Bank_1_0x7001_Value),
    std::make_tuple(0x7001, Expected_Bank_1_0x7000_Value),
    std::make_tuple(0x7002, Expected_Bank_1_0x7003_Value),
    std::make_tuple(0x7003, Expected_Bank_1_0x7002_Value)
));