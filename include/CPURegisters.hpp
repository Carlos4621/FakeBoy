#ifndef CPU_REGISTERS_HPP
#define CPU_REGISTERS_HPP

#include <cstdint>
#include <stdexcept>
#include <array>
#include <utility>

class CPURegisters {
public:

    enum class Registers : uint8_t{ A = 0, F, B, C, D, E, H, L, PC_Up, PC_Low, SP_Up, SP_Low, AuxiliaryUp, AuxiliaryLow };
    enum class CombinedRegisters : uint8_t{ AF = 0, BC, DE, HL, PC, SP, Auxiliary };
    enum class Flags : uint8_t{ Z = 0, N, H, C };

    [[nodiscard]]
    uint8_t getRegister(Registers reg) const noexcept;

    [[nodiscard]]
    uint16_t getCombinedRegister(CombinedRegisters reg) const noexcept;

    [[nodiscard]]
    bool getFlag(Flags flag) const noexcept;

    void setRegister(Registers reg, uint8_t value) noexcept;
    void setCombinedRegister(CombinedRegisters reg, uint16_t value) noexcept;
    void setFlag(Flags flag, bool value) noexcept;

private:

    static constexpr uint16_t HighByteMask{ 0xFF00 };
    static constexpr uint8_t LowByteMask{ 0x00FF};
    static constexpr uint8_t ByteDisplacement{ 8 };

    static constexpr uint8_t FlagsMask_8_Bits{ 0xF0 };
    static constexpr uint16_t FlagsMask_16_Bits{ 0xFFF0 };

    static constexpr uint8_t ZeroFlagMask{ 0b10000000 };
    static constexpr uint8_t SubtractionFlagMask{ 0b01000000 };
    static constexpr uint8_t HalfCarryFlagMask{ 0b00100000 };
    static constexpr uint8_t CarryFlagMask{ 0b00010000 };

    static constexpr uint8_t TotalRegisters{ 8 };

    static constexpr uint16_t InitialAFRegister{ 0x01B0 };
    static constexpr uint16_t InitialBCRegister{ 0x0013 };
    static constexpr uint16_t InitialDERegister{ 0x00D8 };
    static constexpr uint16_t InitialHLRegister{ 0x014D };
    
    static constexpr uint16_t InitialPCRegister{ 0x0100 };
    static constexpr uint16_t InitialSPRegister{ 0xFFFE };

    static constexpr std::array FlagMaskTable{ ZeroFlagMask, SubtractionFlagMask, HalfCarryFlagMask, CarryFlagMask };
    static constexpr std::array<uint8_t, 14> RegisterIndexToCombinedRegisterIndex{ 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6 };

    // REMINDER: Estas son las flags para el DMG, si quiero actualizar a CGB tengo que cambiar esto
    std::array<uint16_t, TotalRegisters> registers_m{ InitialAFRegister, InitialBCRegister, InitialDERegister, InitialHLRegister, InitialPCRegister, InitialSPRegister, 0, 0 };

    [[nodiscard]]
    static constexpr uint8_t getHighByte(uint16_t value) noexcept;

    [[nodiscard]]
    static constexpr uint8_t getLowByte(uint16_t value) noexcept;

    static void setHighByte(uint16_t& value, uint8_t highByte) noexcept;
    static void setLowByte(uint16_t& value, uint8_t lowByte) noexcept;

    [[nodiscard]]
    static constexpr bool isHighByteRegister(Registers reg) noexcept;

    [[nodiscard]]
    static constexpr uint8_t registerToIndex(Registers reg) noexcept;

    [[nodiscard]]
    static constexpr uint8_t combinedRegisterToIndex(CombinedRegisters combinedReg) noexcept;

    [[nodiscard]]
    static constexpr uint8_t flagToIndex(Flags flag) noexcept;

    static void removeLowerBits(uint8_t& value) noexcept;
    static void removeLowerBits(uint16_t& value) noexcept;
};

#endif // !CPU_REGISTERS_HPP