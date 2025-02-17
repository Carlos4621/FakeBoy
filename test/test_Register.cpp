#include "Registers.hpp"
#include <gtest/gtest.h>
#include <utility>

static constexpr uint16_t InitialAF{ 0x1234 };
static constexpr uint16_t InitialBC{ 0x5678 };
static constexpr uint16_t InitialDE{ 0x9ABC };
static constexpr uint16_t InitialHL{ 0xDEF0 };

static constexpr uint8_t InitialA{ 0x12 };
static constexpr uint8_t InitialF{ 0x34 };
static constexpr uint8_t InitialB{ 0x56 };
static constexpr uint8_t InitialC{ 0x78 };
static constexpr uint8_t InitialD{ 0x9A };
static constexpr uint8_t InitialE{ 0xBC };
static constexpr uint8_t InitialH{ 0xDE };
static constexpr uint8_t InitialL{ 0xF0 };

static constexpr bool InitialZFlag{ false };
static constexpr bool InitialNFlag{ true };
static constexpr bool InitialHFlag{ true };
static constexpr bool InitialCFlag{ false };

class CombinedRegisterTest : public ::testing::Test, public ::testing::WithParamInterface<std::pair<Registers::CombinedRegisters, uint8_t> > {
protected:
    Registers registers_m;
};

class StandaloneRegisterTest : public ::testing::Test, public ::testing::WithParamInterface<std::pair<Registers::Register, uint8_t> > {
protected:
    Registers registers_m;
};

class FlagTest : public ::testing::Test, public ::testing::WithParamInterface<std::pair<Registers::Flags, bool> > {
protected:
    Registers registers_m;
} ;

TEST_P(CombinedRegisterTest, SetGetCombinedRegisterWorks) {
    const auto [combinedRegister, expectedValue] = GetParam();

    registers_m.setCombinedRegister(combinedRegister, expectedValue);

    EXPECT_EQ(registers_m.getCombinedRegister(combinedRegister), expectedValue);
}

TEST_P(StandaloneRegisterTest, SetGetRegisterWorks) {
    const auto [standaloneRegister, expectedValue] = GetParam();

    registers_m.setRegister(standaloneRegister, expectedValue);

    EXPECT_EQ(registers_m.getRegister(standaloneRegister), expectedValue);
}

TEST_P(FlagTest, SetGetFlagWorks) {
    const auto [flag, expectedValue] = GetParam();

    registers_m.setFlag(flag, expectedValue);

    EXPECT_EQ(registers_m.getFlag(flag), expectedValue);
}

INSTANTIATE_TEST_SUITE_P(CombinedRegisters, CombinedRegisterTest, ::testing::Values(
    std::make_pair(Registers::CombinedRegisters::AF, InitialAF),
    std::make_pair(Registers::CombinedRegisters::BC, InitialBC),
    std::make_pair(Registers::CombinedRegisters::DE, InitialDE),
    std::make_pair(Registers::CombinedRegisters::HL, InitialHL)
));

INSTANTIATE_TEST_SUITE_P(StandaloneRegisters, StandaloneRegisterTest, ::testing::Values(
    std::make_pair(Registers::Register::A, InitialA),
    std::make_pair(Registers::Register::F, InitialF),
    std::make_pair(Registers::Register::B, InitialB),
    std::make_pair(Registers::Register::C, InitialC),
    std::make_pair(Registers::Register::D, InitialD),
    std::make_pair(Registers::Register::E, InitialE),
    std::make_pair(Registers::Register::H, InitialH),
    std::make_pair(Registers::Register::L, InitialL)
));

INSTANTIATE_TEST_SUITE_P(Flags, FlagTest, ::testing::Values(
    std::make_pair(Registers::Flags::Z, InitialZFlag),
    std::make_pair(Registers::Flags::N, InitialNFlag),
    std::make_pair(Registers::Flags::H, InitialHFlag),
    std::make_pair(Registers::Flags::C, InitialCFlag)
));