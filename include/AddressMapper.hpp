#ifndef ADDRESS_MAPPER_HPP
#define ADDRESS_MAPPER_HPP

#include <cstdint>
#include <array>
#include <stdexcept>

template <uint16_t StartAddress, uint16_t EndAddress>
class AddressMapper {
public:

    [[nodiscard]]
    constexpr uint8_t read(uint16_t address) const;

    constexpr void write(uint16_t address, uint8_t value);

    constexpr void enable() noexcept;
    constexpr void disable() noexcept;

private:

    static constexpr uint8_t DisabledMemoryReadValue{ 0xFF };

    std::array<uint8_t, EndAddress - StartAddress + 1> memory_m{};

    bool enabled_m{ true };

    static constexpr void throwIfInvalidAddress(uint16_t address);

    [[nodiscard]]
    static constexpr uint16_t getRedirectedAddress(uint16_t address) noexcept;
};

template <uint16_t StartAddress, uint16_t EndAddress>
constexpr uint8_t AddressMapper<StartAddress, EndAddress>::read(uint16_t address) const {
    throwIfInvalidAddress(address);

    if (!enabled_m) {
        return DisabledMemoryReadValue;
    }
    
    return memory_m[getRedirectedAddress(address)];
}

template <uint16_t StartAddress, uint16_t EndAddress>
constexpr void AddressMapper<StartAddress, EndAddress>::write(uint16_t address, uint8_t value) {
    throwIfInvalidAddress(address);

    if (enabled_m) {
        memory_m[getRedirectedAddress(address)] = value;
    }
}

template <uint16_t StartAddress, uint16_t EndAddress>
constexpr void AddressMapper<StartAddress, EndAddress>::enable() noexcept {
    enabled_m = true;
}

template <uint16_t StartAddress, uint16_t EndAddress>
constexpr void AddressMapper<StartAddress, EndAddress>::disable() noexcept {
    enabled_m = false;
}

template <uint16_t StartAddress, uint16_t EndAddress>
constexpr void AddressMapper<StartAddress, EndAddress>::throwIfInvalidAddress(uint16_t address) {
    if (address < StartAddress || address > EndAddress) {
        throw std::out_of_range("Invalid address: " + std::to_string(address) + " for range: " + std::to_string(StartAddress) + " - " + std::to_string(EndAddress));
    }
}

template <uint16_t StartAddress, uint16_t EndAddress>
constexpr uint16_t AddressMapper<StartAddress, EndAddress>::getRedirectedAddress(uint16_t address) noexcept {
    return (address - StartAddress);
}

#endif // !ADDRESS_MAPPER_HPP