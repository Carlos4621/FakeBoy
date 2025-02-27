#include "Cartridge.hpp"

Cartridge::Cartridge(std::string_view romPath) {
    loadCartridge(romPath);
    determineMBC();
    determineRAM();
}

void Cartridge::write(uint16_t address, uint8_t value) {
    // REMINDER: Los distintos tipos de MBC tienen distintas direcciones para su registro, manejar correctamente

    switch (determineMemoryRange(address)) {
    case MemoryRange::Bank_0:
    case MemoryRange::SwitchableROMBanks:
        mbc_m->writeToRegisters(address, value);
        break;

    case MemoryRange::ExternalRAM:
        writeToRAM(address, value);
        break;

    default:
        throwInvalidAddress(address);
        break;
    }
}

uint8_t Cartridge::read(uint16_t address) {
    switch (determineMemoryRange(address)) {
    case MemoryRange::Bank_0:
        return readFromBank_0(address);
        break;
    
    case MemoryRange::SwitchableROMBanks:
        return readFromSwitchableBank(address);
        break;

    case MemoryRange::ExternalRAM:
        return readFromRAM(address);
        break;
    
    default:
        throwInvalidAddress(address);
        break;
    }
}

uint8_t Cartridge::directReadToFile(uint16_t address) {
    uint8_t byte{};
    romFile_m.seekg(address);
    romFile_m.read(reinterpret_cast<char*>(&byte), sizeof(byte));

    return byte;
}

uint8_t Cartridge::readFromBank_0(uint16_t address) {
    return directReadToFile(address);
}

uint8_t Cartridge::readFromSwitchableBank(uint16_t address) {
    const auto redirectedAddress{ mbc_m->getRedirected_ROM_address(address) };

    return directReadToFile(redirectedAddress);
}

uint8_t Cartridge::readFromRAM(uint16_t address) {
    if (mbc_m->isRAM_enabled() && !RAM_m.empty()) {
        const auto redirectedAddress{ mbc_m->getRedirected_RAM_address(address) };

        return RAM_m[redirectedAddress];
    }

    return RAM_Disabled_Read_Value;
}

void Cartridge::writeToRAM(uint16_t address, uint8_t value) {
    if (mbc_m->isRAM_enabled() && !RAM_m.empty()) {
        const auto redirectedAddress{ mbc_m->getRedirected_RAM_address(address) };

        RAM_m[redirectedAddress] = value;
    }
}

void Cartridge::loadCartridge(std::string_view romPath) {
    romFile_m.open(romPath.data(), std::ios::binary);

    throwIfFileNotOpen();
}

void Cartridge::throwIfFileNotOpen() const {
    if (!romFile_m.is_open()) {
        throw std::runtime_error("ROM file is not open");
    }
}

void Cartridge::determineMBC() {
    const auto MBC_type{ directReadToFile(MBC_Identifier_Address) };

    switch (MBC_type) {
    case MBCBase::NoMBC_Identifier:
        mbc_m = std::make_unique<NoMBC>();
        break;

    default:
        throw std::runtime_error{ "MBC not supported" + std::to_string(MBC_type) };
        break;
    }
}

void Cartridge::determineRAM() {
    const auto RAM_identifier{ directReadToFile(RAM_Size_Address) };

    switch (RAM_identifier) {
    case No_RAM_Identifier:
        break;

    case RAM_8KB_Identifier:
        RAM_m.resize(KB_8);
        break;

    case RAM_32KB_Identifier:
        RAM_m.resize(KB_32);
        break;

    case RAM_128KB_Identifier:
        RAM_m.resize(KB_128);
        break;

    case RAM_64KB_Identifier:
        RAM_m.resize(KB_64);
        break;

    default:
        throw std::invalid_argument{ "Invalid RAM identifier" + std::to_string(RAM_identifier) };
        break;
    }
}

void Cartridge::throwInvalidAddress(uint16_t address) {
    throw std::out_of_range{ "Invalid address" + std::to_string(address) };
}
