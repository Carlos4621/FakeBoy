#pragma once
#ifndef NO_MBC_HPP
#define NO_MBC_HPP

#include "MBCBase.hpp"
#include "MemoryMap.hpp"

class NoMBC : public MBCBase {
public:

    NoMBC();
    NoMBC(const NoMBC&) = default;
    NoMBC(NoMBC&&) noexcept = default;

    ~NoMBC() override = default;

    NoMBC& operator=(const NoMBC&) = default;
    NoMBC& operator=(NoMBC&&) noexcept = default;

    void writeToRegisters(uint16_t address, uint8_t value) override;

    [[nodiscard]]
    uint16_t getRedirected_ROM_address(uint16_t address) const noexcept override;

    [[nodiscard]]
    uint16_t getRedirected_RAM_address(uint16_t address) const noexcept override;
};

#endif // !NO_MBC_HPP