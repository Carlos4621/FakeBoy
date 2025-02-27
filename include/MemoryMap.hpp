#pragma once
#ifndef MEMORY_MAP_HPP
#define MEMORY_MAP_HPP

#include <cstdint>
#include <utility>

enum class MemoryRange : uint8_t {
    Bank_0 = 0,
    SwitchableROMBanks,
    ExternalRAM,
    Work_RAM,
    Echo_RAM,
    OAM,
    Not_Usable,
    IO_Registers,
    High_RAM,
    Interrupt_Enable_Register
};

static constexpr uint16_t Bank_0_End_Address{ 0x3FFF };

static constexpr uint16_t Switchable_Bank_Start_Address{ 0x4000 };
static constexpr uint16_t Switchable_Bank_End_Address{ 0x7FFF };

static constexpr uint16_t RAM_Start_Address{ 0xA000 };
static constexpr uint16_t RAM_End_Adress{ 0xBFFF };

static constexpr uint16_t Work_RAM_Start_Address{ 0xC000 };
static constexpr uint16_t Work_RAM_End_Address{ 0xDFFF };

static constexpr uint16_t Echo_RAM_Start_Address{ 0xE000 };
static constexpr uint16_t Echo_RAM_End_Address{ 0xFDFF };

static constexpr uint16_t OAM_Start_Address{ 0xFE00 };
static constexpr uint16_t OAM_End_Address{ 0xFE9F };

static constexpr uint16_t Not_Usable_Start_Address{ 0xFEA0 };
static constexpr uint16_t Not_Usable_End_Address{ 0xFEFF };

static constexpr uint16_t IO_Registers_Start_Address{ 0xFF00 };
static constexpr uint16_t IO_Registers_End_Address{ 0xFF7F };

static constexpr uint16_t High_RAM_Start_Address{ 0xFF80 };
static constexpr uint16_t High_RAM_End_Address{ 0xFFFE };

static constexpr uint16_t Interrupt_Enable_Register_Address{ 0xFFFF };

static constexpr uint16_t MBC_Identifier_Address{ 0x147 };
static constexpr uint16_t RAM_Size_Address{ 0x148 };

static constexpr bool isOnBank_0_range(uint16_t address) noexcept{
    return (address <= Bank_0_End_Address);
}

static constexpr bool isOnSwitchableROMBank_range(uint16_t address) noexcept {
    return  (address >= Switchable_Bank_Start_Address) && (address <= Switchable_Bank_End_Address);
}

static constexpr bool isOnExternalRAM_range(uint16_t address) noexcept {
    return (address >= RAM_Start_Address) && (address <= RAM_End_Adress);
}

static constexpr bool isOnWorkRAM_range(uint16_t address) noexcept {
    return (address >= Work_RAM_Start_Address) && (address <= Work_RAM_End_Address);
}

static constexpr bool isOnEchoRAM_range(uint16_t address) noexcept {
    return (address >= Echo_RAM_Start_Address) && (address <= Echo_RAM_End_Address);
}

static constexpr bool isOnOAM_range(uint16_t address) noexcept {
    return (address >= OAM_Start_Address) && (address <= OAM_End_Address);
}

static constexpr bool isOnNotUsable_range(uint16_t address) noexcept {
    return (address >= Not_Usable_Start_Address) && (address <= Not_Usable_End_Address);
}

static constexpr bool isOnIORegisters_range(uint16_t address) noexcept {
    return (address >= IO_Registers_Start_Address) && (address <= IO_Registers_End_Address);
}

static constexpr bool isOnHighRAM_range(uint16_t address) noexcept {
    return (address >= High_RAM_Start_Address) && (address <= High_RAM_End_Address);
}

static constexpr bool isOnInterruptEnableRegister_range(uint16_t address) noexcept {
    return (address == Interrupt_Enable_Register_Address);
}

static constexpr MemoryRange determineMemoryRange(uint16_t address) noexcept {
    if (isOnBank_0_range(address)) {
        return MemoryRange::Bank_0;
    }

    if (isOnSwitchableROMBank_range(address)) {
        return MemoryRange::SwitchableROMBanks;
    }

    if (isOnExternalRAM_range(address)) {
        return MemoryRange::ExternalRAM;
    }    

    if (isOnWorkRAM_range(address)) {
        return MemoryRange::Work_RAM;
    }

    if (isOnEchoRAM_range(address)) {
        return MemoryRange::Echo_RAM;
    }

    if (isOnOAM_range(address)) {
        return MemoryRange::OAM;
    }

    if (isOnNotUsable_range(address)) {
        return MemoryRange::Not_Usable;
    }

    if (isOnIORegisters_range(address)) {
        return MemoryRange::IO_Registers;
    }

    if (isOnHighRAM_range(address)) {
        return MemoryRange::High_RAM;
    }

    if (isOnInterruptEnableRegister_range(address)) {
        return MemoryRange::Interrupt_Enable_Register;
    }

    std::unreachable();
}

#endif // !MEMORY_MAP_HPP