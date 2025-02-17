#pragma once
#ifndef REGISTERS_HPP
#define REGISTERS_HPP

#include <cstdint>
#include <stdexcept>

class Registers {
public:

    enum class Register : uint8_t{ A, B, C, D, E, H, L, F };
    enum class CombinedRegisters : uint8_t{ AF, BC, DE, HL };
    enum class Flags : uint8_t{ Z, N, H, C };

    [[nodiscard]]
    uint8_t getRegister(Register reg) const noexcept;

    [[nodiscard]]
    uint16_t getCombinedRegister(CombinedRegisters reg) const noexcept;

    [[nodiscard]]
    bool getFlag(Flags flag) const noexcept;

    void setRegister(Register reg, uint8_t value) noexcept;
    void setCombinedRegister(CombinedRegisters reg, uint16_t value) noexcept;
    void setFlag(Flags flag, bool value) noexcept;

private:
    static constexpr uint16_t HighByteMask{ 0xFF00 };
    static constexpr uint8_t LowByteMask{ 0x00FF};
    static constexpr uint8_t ByteDisplacement{ 8 };

    static constexpr uint8_t ZeroFlagMask{ 0b10000000 };
    static constexpr uint8_t SubtractionFlagMask{ 0b01000000 };
    static constexpr uint8_t HalfCarryFlagMask{ 0b00100000 };
    static constexpr uint8_t CarryFlagMask{ 0b00010000 };

    uint16_t AF_register_m;
    uint16_t BC_register_m;
    uint16_t DE_register_m;
    uint16_t HL_register_m;

    [[nodiscard]]
    static uint8_t getHighByte(uint16_t value) noexcept;

    [[nodiscard]]
    static uint8_t getLowByte(uint16_t value) noexcept;

    static void setHighByte(uint16_t& value, uint8_t highByte) noexcept;
    static void setLowByte(uint16_t& value, uint8_t lowByte) noexcept;
};

#endif // !REGISTERS_HPP