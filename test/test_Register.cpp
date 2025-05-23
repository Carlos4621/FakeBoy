#include "CPURegisters.hpp"
#include <gtest/gtest.h>
#include <utility>

static constexpr uint16_t InitialAF{ 0x1230 };
static constexpr uint16_t toMaskAF{ 0xFFFF };

static constexpr uint16_t InitialBC{ 0x5678 };
static constexpr uint16_t InitialDE{ 0x9ABC };
static constexpr uint16_t InitialHL{ 0xDEF0 };
static constexpr uint16_t InitialPC{ 0x0101 };
static constexpr uint16_t InitialSP{ 0x1111 };

static constexpr uint16_t MaskedAF{ toMaskAF & 0xFFF0 };

static constexpr uint8_t InitialA{ 0x12 };
static constexpr uint8_t InitialF{ 0x34 };
static constexpr uint8_t InitialB{ 0x56 };
static constexpr uint8_t InitialC{ 0x78 };
static constexpr uint8_t InitialD{ 0x9A };
static constexpr uint8_t InitialE{ 0xBC };
static constexpr uint8_t InitialH{ 0xDE };
static constexpr uint8_t InitialL{ 0xF0 };
static constexpr uint8_t InitialPC_Low{ 0x99 };
static constexpr uint8_t InitialPC_Up{ 0x22 };
static constexpr uint8_t InitialSP_Low{ 0x11 };
static constexpr uint8_t InitialSP_Up{ 0xFE };

static constexpr uint8_t MaskedF{ toMaskAF & 0xF0 };

static constexpr bool InitialZFlag{ false };
static constexpr bool InitialNFlag{ true };
static constexpr bool InitialHFlag{ true };
static constexpr bool InitialCFlag{ false };

class CombinedRegisterTest : public ::testing::Test, public ::testing::WithParamInterface<std::tuple<CPURegisters::CombinedRegisters, uint8_t, CPURegisters::CombinedRegisters> > {
protected:
    CPURegisters registers_m;
};

class StandaloneRegisterTest : public ::testing::Test, public ::testing::WithParamInterface<std::tuple<CPURegisters::Registers, uint8_t, CPURegisters::Registers> > {
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
    registers_m.setCombinedRegister(CPURegisters::CombinedRegisters::AF, toMaskAF);

    EXPECT_EQ(registers_m.getCombinedRegister(CPURegisters::CombinedRegisters::AF), MaskedAF);
    EXPECT_EQ(registers_m.getRegister(CPURegisters::Registers::F), MaskedF);
}

INSTANTIATE_TEST_SUITE_P(CombinedRegisters, CombinedRegisterTest, ::testing::Values(
    std::make_tuple(CPURegisters::CombinedRegisters::BC, InitialBC, CPURegisters::CombinedRegisters::AF),
    std::make_tuple(CPURegisters::CombinedRegisters::DE, InitialDE, CPURegisters::CombinedRegisters::HL),
    std::make_tuple(CPURegisters::CombinedRegisters::HL, InitialHL, CPURegisters::CombinedRegisters::DE),
    std::make_tuple(CPURegisters::CombinedRegisters::AF, InitialAF, CPURegisters::CombinedRegisters::BC),
    std::make_tuple(CPURegisters::CombinedRegisters::PC, InitialPC, CPURegisters::CombinedRegisters::SP),
    std::make_tuple(CPURegisters::CombinedRegisters::SP, InitialSP, CPURegisters::CombinedRegisters::PC)
));

INSTANTIATE_TEST_SUITE_P(StandaloneRegisters, StandaloneRegisterTest, ::testing::Values(
    std::make_tuple(CPURegisters::Registers::A, InitialA, CPURegisters::Registers::F),
    std::make_tuple(CPURegisters::Registers::B, InitialB, CPURegisters::Registers::C),
    std::make_tuple(CPURegisters::Registers::C, InitialC, CPURegisters::Registers::B),
    std::make_tuple(CPURegisters::Registers::D, InitialD, CPURegisters::Registers::E),
    std::make_tuple(CPURegisters::Registers::E, InitialE, CPURegisters::Registers::D),
    std::make_tuple(CPURegisters::Registers::H, InitialH, CPURegisters::Registers::L),
    std::make_tuple(CPURegisters::Registers::L, InitialL, CPURegisters::Registers::H),
    std::make_tuple(CPURegisters::Registers::PC_Up, InitialPC_Up, CPURegisters::Registers::PC_Low),
    std::make_tuple(CPURegisters::Registers::PC_Low, InitialPC_Low, CPURegisters::Registers::PC_Up),
    std::make_tuple(CPURegisters::Registers::SP_Up, InitialL, CPURegisters::Registers::SP_Low),
    std::make_tuple(CPURegisters::Registers::SP_Low, InitialL, CPURegisters::Registers::SP_Up)
));

INSTANTIATE_TEST_SUITE_P(Flags, FlagTest, ::testing::Values(
    std::make_tuple(CPURegisters::Flags::Z, InitialZFlag, CPURegisters::Flags::N),
    std::make_tuple(CPURegisters::Flags::N, InitialNFlag, CPURegisters::Flags::Z),
    std::make_tuple(CPURegisters::Flags::H, InitialHFlag, CPURegisters::Flags::C),
    std::make_tuple(CPURegisters::Flags::C, InitialCFlag, CPURegisters::Flags::H)
));