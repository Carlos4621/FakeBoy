#include "CPURegisters.hpp"
#include <gtest/gtest.h>
#include <utility>

static constexpr uint16_t InitialAF{ 0x1234 };
static constexpr uint16_t InitialBC{ 0x5678 };
static constexpr uint16_t InitialDE{ 0x9ABC };
static constexpr uint16_t InitialHL{ 0xDEF0 };

static constexpr uint16_t MaskedAF{ InitialAF & 0xFFF0 };

static constexpr uint8_t InitialA{ 0x12 };
static constexpr uint8_t InitialF{ 0x34 };
static constexpr uint8_t InitialB{ 0x56 };
static constexpr uint8_t InitialC{ 0x78 };
static constexpr uint8_t InitialD{ 0x9A };
static constexpr uint8_t InitialE{ 0xBC };
static constexpr uint8_t InitialH{ 0xDE };
static constexpr uint8_t InitialL{ 0xF0 };

static constexpr uint8_t MaskedF{ InitialF & 0xF0 };

static constexpr bool InitialZFlag{ false };
static constexpr bool InitialNFlag{ true };
static constexpr bool InitialHFlag{ true };
static constexpr bool InitialCFlag{ false };

class CombinedRegisterTest : public ::testing::Test, public ::testing::WithParamInterface<std::tuple<CPURegisters::CombinedRegisters, uint8_t, CPURegisters::CombinedRegisters> > {
protected:
    CPURegisters registers_m;
};

class StandaloneRegisterTest : public ::testing::Test, public ::testing::WithParamInterface<std::tuple<CPURegisters::Register, uint8_t, CPURegisters::Register> > {
protected:
    CPURegisters registers_m;
};

class FlagTest : public ::testing::Test, public ::testing::WithParamInterface<std::tuple<CPURegisters::Flags, bool, CPURegisters::Flags> > {
protected:
    CPURegisters registers_m;
};

class FlagMaskTest : public ::testing::Test {
protected:
    CPURegisters registers_m;
};

TEST_P(CombinedRegisterTest, SetGetCombinedRegisterWorks) {
    const auto [combinedRegister, expectedValue, unexpectedValue] = GetParam();

    registers_m.setCombinedRegister(combinedRegister, expectedValue);

    EXPECT_EQ(registers_m.getCombinedRegister(combinedRegister), expectedValue);
    EXPECT_NE(registers_m.getCombinedRegister(combinedRegister), registers_m.getCombinedRegister(unexpectedValue));
}

TEST_P(StandaloneRegisterTest, SetGetRegisterWorks) {
    const auto [standaloneRegister, expectedValue, unexpectedEquality] = GetParam();

    registers_m.setRegister(standaloneRegister, expectedValue);

    EXPECT_EQ(registers_m.getRegister(standaloneRegister), expectedValue);
    EXPECT_NE(registers_m.getRegister(standaloneRegister), registers_m.getRegister(unexpectedEquality));
}

TEST_P(FlagTest, SetGetFlagWorks) {
    const auto [flag, expectedValue, unexpectedValue] = GetParam();

    registers_m.setFlag(flag, expectedValue);
    registers_m.setFlag(unexpectedValue, !expectedValue);

    EXPECT_EQ(registers_m.getFlag(flag), expectedValue);
    EXPECT_NE(registers_m.getFlag(flag), registers_m.getFlag(unexpectedValue));
}

TEST_F(FlagMaskTest, FlagsMaskWorks) {
    registers_m.setCombinedRegister(CPURegisters::CombinedRegisters::AF, InitialAF);

    EXPECT_EQ(registers_m.getCombinedRegister(CPURegisters::CombinedRegisters::AF), MaskedAF);
    EXPECT_EQ(registers_m.getRegister(CPURegisters::Register::F), MaskedF);
}

INSTANTIATE_TEST_SUITE_P(CombinedRegisters, CombinedRegisterTest, ::testing::Values(
    std::make_tuple(CPURegisters::CombinedRegisters::BC, InitialBC, CPURegisters::CombinedRegisters::AF),
    std::make_tuple(CPURegisters::CombinedRegisters::DE, InitialDE, CPURegisters::CombinedRegisters::HL),
    std::make_tuple(CPURegisters::CombinedRegisters::HL, InitialHL, CPURegisters::CombinedRegisters::DE)
));

INSTANTIATE_TEST_SUITE_P(StandaloneRegisters, StandaloneRegisterTest, ::testing::Values(
    std::make_tuple(CPURegisters::Register::A, InitialA, CPURegisters::Register::F),
    std::make_tuple(CPURegisters::Register::B, InitialB, CPURegisters::Register::C),
    std::make_tuple(CPURegisters::Register::C, InitialC, CPURegisters::Register::B),
    std::make_tuple(CPURegisters::Register::D, InitialD, CPURegisters::Register::E),
    std::make_tuple(CPURegisters::Register::E, InitialE, CPURegisters::Register::D),
    std::make_tuple(CPURegisters::Register::H, InitialH, CPURegisters::Register::L),
    std::make_tuple(CPURegisters::Register::L, InitialL, CPURegisters::Register::H)
));

INSTANTIATE_TEST_SUITE_P(Flags, FlagTest, ::testing::Values(
    std::make_tuple(CPURegisters::Flags::Z, InitialZFlag, CPURegisters::Flags::N),
    std::make_tuple(CPURegisters::Flags::N, InitialNFlag, CPURegisters::Flags::Z),
    std::make_tuple(CPURegisters::Flags::H, InitialHFlag, CPURegisters::Flags::C),
    std::make_tuple(CPURegisters::Flags::C, InitialCFlag, CPURegisters::Flags::H)
));