#pragma once
#ifndef MEMORY_MAP_HPP
#define MEMORY_MAP_HPP

#include <cstdint>

static constexpr uint16_t Bank_0_End_Address{ 0x3FFF };
static constexpr uint16_t Banks_End_Address{ 0x7FFF };

static constexpr uint16_t RAM_Start_Address{ 0xA000 };
static constexpr uint16_t RAM_End_Adress{ 0xBFFF };

static constexpr uint16_t MBC_Identifier_Address{ 0x147 };
static constexpr uint16_t RAM_Size_Address{ 0x148 };

static constexpr bool isOnBank_0_range(uint16_t address) noexcept{
    return (address <= Bank_0_End_Address);
}

static constexpr bool isOnSwitchableBanks_range(uint16_t address) noexcept {
    return  (address > Bank_0_End_Address) && (address <= Banks_End_Address);
}

static constexpr bool isOnRAM_range(uint16_t address) noexcept {
    return (address >= RAM_Start_Address) && (address <= RAM_End_Adress);
}

#endif // !MEMORY_MAP_HPP