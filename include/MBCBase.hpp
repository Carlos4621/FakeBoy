#pragma once
#ifndef MBC_INTERFACE_HPP
#define MBC_INTERFACE_HPP

#include <cstdint>

class MBCBase {
public:

    static constexpr uint8_t NoMBC_Identifier{ 0x00 };

    MBCBase() = default;
    MBCBase(const MBCBase&) = default;
    MBCBase(MBCBase&&) noexcept = default;

    virtual ~MBCBase() noexcept = default;

    MBCBase& operator=(const MBCBase&) = default;
    MBCBase& operator=(MBCBase&&) noexcept = default;

    virtual void writeToRegisters(uint16_t address, uint8_t value) = 0;

    [[nodiscard]]
    virtual uint16_t getRedirected_ROM_address(uint16_t address) const noexcept = 0;

    [[nodiscard]]
    virtual uint16_t getRedirected_RAM_address(uint16_t address) const noexcept = 0;

    [[nodiscard]]
    bool isRAM_enabled() const noexcept;

protected:

    void enableRAM() noexcept;
    void disableRAM() noexcept;

private:

    bool RAM_enabled_m{ false };

};

#endif // !MBC_INTERFACE_HPP