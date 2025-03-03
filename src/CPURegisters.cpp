#include <CPURegisters.hpp>

uint8_t CPURegisters::getRegister(Registers reg) const noexcept {
    const auto combinedRegister{ registers_m[RegisterIndexToCombinedRegisterIndex[registerToIndex(reg)]] };

    return isHighByteRegister(reg) ? getHighByte(combinedRegister) : getLowByte(combinedRegister);
}

uint16_t CPURegisters::getCombinedRegister(CombinedRegisters reg) const noexcept {
    return registers_m[combinedRegisterToIndex(reg)];
}

bool CPURegisters::getFlag(Flags flag) const noexcept {    
    return (getRegister(Registers::F) & FlagMaskTable[flagToIndex(flag)]) != 0;
}

void CPURegisters::setRegister(Registers reg, uint8_t value) noexcept {
    auto& combinedRegister{ registers_m[RegisterIndexToCombinedRegisterIndex[registerToIndex(reg)]] };

    if (reg == Registers::F) {
        removeLowerBits(value);
    }

    if (isHighByteRegister(reg)) {
        setHighByte(combinedRegister, value);
    } else {
        setLowByte(combinedRegister, value);
    }
}

void CPURegisters::setCombinedRegister(CombinedRegisters reg, uint16_t value) noexcept {
    if (reg == CombinedRegisters::AF) {
        removeLowerBits(value);
    }

    registers_m[combinedRegisterToIndex(reg)] = value;
}

void CPURegisters::setFlag(Flags flag, bool value) noexcept {
    uint8_t F_register{ getRegister(Registers::F) };

    if (const uint8_t flagIndex{ flagToIndex(flag) }; value) {
        F_register |= FlagMaskTable[flagIndex];
    } else {
        F_register &= ~FlagMaskTable[flagIndex];
    }

    setRegister(Registers::F, F_register);
}

constexpr uint8_t CPURegisters::getHighByte(uint16_t value) noexcept {
    return static_cast<uint8_t>(value >> ByteDisplacement);
}

constexpr uint8_t CPURegisters::getLowByte(uint16_t value) noexcept {
    return static_cast<uint8_t>(value & LowByteMask);
}

void CPURegisters::setHighByte(uint16_t &value, uint8_t highByte) noexcept {
    value = (value & LowByteMask) | (static_cast<uint16_t>(highByte) << ByteDisplacement);
}

void CPURegisters::setLowByte(uint16_t &value, uint8_t lowByte) noexcept {
    value = (value & HighByteMask) | lowByte;
}

constexpr bool CPURegisters::isHighByteRegister(Registers reg) noexcept {
    return (registerToIndex(reg) % 2) == 0;
}

constexpr uint8_t CPURegisters::registerToIndex(Registers reg) noexcept {
    return std::to_underlying(reg);
}

constexpr uint8_t CPURegisters::combinedRegisterToIndex(CombinedRegisters combinedReg) noexcept {
    return std::to_underlying(combinedReg);
}

constexpr uint8_t CPURegisters::flagToIndex(Flags flag) noexcept {
    return std::to_underlying(flag);
}

void CPURegisters::removeLowerBits(uint8_t &value) noexcept {
    value &= FlagsMask_8_Bits;
}

void CPURegisters::removeLowerBits(uint16_t &value) noexcept {
    value &= FlagsMask_16_Bits;
}
