#include <Registers.hpp>

uint8_t Registers::getRegister(Register reg) const noexcept {
    switch (reg) {
    case Register::A:
        return getHighByte(AF_register_m);

    case Register::F:
        return getLowByte(AF_register_m);

    case Register::B:
        return getHighByte(BC_register_m);

    case Register::C:
        return getLowByte(BC_register_m);

    case Register::D:
        return getHighByte(DE_register_m);

    case Register::E:
        return getLowByte(DE_register_m);

    case Register::H:
        return getHighByte(HL_register_m);
        
    case Register::L:
        return getLowByte(HL_register_m);
    }

    return 0;
}

uint16_t Registers::getCombinedRegister(CombinedRegisters reg) const noexcept {
    switch (reg) {
    case CombinedRegisters::AF:
        return AF_register_m;

    case CombinedRegisters::BC:
        return BC_register_m;

    case CombinedRegisters::DE:
        return DE_register_m;

    case CombinedRegisters::HL:
        return HL_register_m;
    }

    return 0;
}

bool Registers::getFlag(Flags flag) const noexcept {
    switch (flag) {
    case Flags::Z:
        return getRegister(Register::F) & ZeroFlagMask;

    case Flags::N:
        return getRegister(Register::F) & SubtractionFlagMask;

    case Flags::H:
        return getRegister(Register::F) & HalfCarryFlagMask;

    case Flags::C:
        return getRegister(Register::F) & CarryFlagMask;
    }

    return false;
}

void Registers::setRegister(Register reg, uint8_t value) noexcept {
    switch (reg) {
    case Register::A:
        setHighByte(AF_register_m, value);
        break;

    case Register::F:
        setLowByte(AF_register_m, value);
        break;

    case Register::B:
        setHighByte(BC_register_m, value);
        break;

    case Register::C:
        setLowByte(BC_register_m, value);
        break;

    case Register::D:
        setHighByte(DE_register_m, value);
        break;

    case Register::E:
        setLowByte(DE_register_m, value);
        break;

    case Register::H:
        setHighByte(HL_register_m, value);
        break;

    case Register::L:
        setLowByte(HL_register_m, value);
        break;
    }
}

void Registers::setCombinedRegister(CombinedRegisters reg, uint16_t value) noexcept {
    switch (reg) {
    case CombinedRegisters::AF:
        AF_register_m = value;
        break;

    case CombinedRegisters::BC:
        BC_register_m = value;
        break;

    case CombinedRegisters::DE:
        DE_register_m = value;
        break;

    case CombinedRegisters::HL:
        HL_register_m = value;
        break;
    }
}

void Registers::setFlag(Flags flag, bool value) noexcept {
    uint8_t F_register{ getRegister(Register::F) };

    switch (flag) {
    case Flags::Z:
        if (value) {
            F_register |= ZeroFlagMask;
        } else {
            F_register &= ~ZeroFlagMask;
        }
        break;

    case Flags::N:
        if (value) {
            F_register |= SubtractionFlagMask;
        } else {
            F_register &= ~SubtractionFlagMask;
        }
        break;

    case Flags::H:
        if (value) {
            F_register |= HalfCarryFlagMask;
        } else {
            F_register &= ~HalfCarryFlagMask;
        }
        break;

    case Flags::C:
        if (value) {
            F_register |= CarryFlagMask;
        } else {
            F_register &= ~CarryFlagMask;
        }
        break;
    }

    setRegister(Register::F, F_register);
}

uint8_t Registers::getHighByte(uint16_t value) noexcept {
    return static_cast<uint8_t>(value >> ByteDisplacement);
}

uint8_t Registers::getLowByte(uint16_t value) noexcept {
    return static_cast<uint8_t>(value & LowByteMask);
}

void Registers::setHighByte(uint16_t &value, uint8_t highByte) noexcept {
    value = (value & LowByteMask) | (static_cast<uint16_t>(highByte) << ByteDisplacement);
}

void Registers::setLowByte(uint16_t &value, uint8_t lowByte) noexcept {
    value = (value & HighByteMask) | lowByte;
}
