#include "NoMBC.hpp"

NoMBC::NoMBC() {
    // Al no haber MBC, la RAM siempre está habilitada
    enableRAM();
}

void NoMBC::writeToRegisters(uint16_t address, uint8_t value) {
    // Sin MBC, no hay registros que escribir
}

uint16_t NoMBC::getRedirected_ROM_address(uint16_t address) const noexcept {
    return address;
}

uint16_t NoMBC::getRedirected_RAM_address(uint16_t address) const noexcept {
    return (address - External_RAM_Start_Address);
}
