#ifndef CARTRIDGE_HPP
#define CARTRIDGE_HPP

#include <fstream>
#include <string_view>
#include <memory>
#include "MBCBase.hpp"
#include "NoMBC.hpp"
#include <vector>
#include "MemoryMap.hpp"

// TODO: Una vez terminados las clases de manejo de memoria, hacer superclase de estos
class Cartridge {
public:

    explicit Cartridge(std::string_view romPath);

    void write(uint16_t address, uint8_t value);

    [[nodiscard]]
    uint8_t read(uint16_t address);

private:
    static constexpr uint8_t RAM_Disabled_Read_Value{ 0xFF };

    static constexpr uint8_t No_RAM_Identifier{ 0x00 };
    static constexpr uint8_t RAM_8KB_Identifier{ 0x02 };
    static constexpr uint8_t RAM_32KB_Identifier{ 0x03 };
    static constexpr uint8_t RAM_128KB_Identifier{ 0x04 };
    static constexpr uint8_t RAM_64KB_Identifier{ 0x05 };

    static constexpr uint32_t KB_8{ 8 * 1024 };
    static constexpr uint32_t KB_32{ 32 * 1024 };
    static constexpr uint32_t KB_128{ 128 * 1024 };
    static constexpr uint32_t KB_64{ 64 * 1024 };

    std::ifstream romFile_m;
    std::vector<uint8_t> RAM_m;

    std::unique_ptr<MBCBase> mbc_m;

    [[nodiscard]]
    uint8_t directReadToFile(uint16_t address);

    [[nodiscard]]
    uint8_t readFromBank_0(uint16_t address);

    [[nodiscard]]
    uint8_t readFromSwitchableBank(uint16_t address);

    [[nodiscard]]
    uint8_t readFromRAM(uint16_t address) const;
    
    void writeToRAM(uint16_t address, uint8_t value);

    void loadCartridge(std::string_view romPath);
    void throwIfFileNotOpen() const;

    void determineMBC();
    void determineRAM();

    [[noreturn]]
    static void throwInvalidAddress(uint16_t address);
};

#endif // !CARTRIDGE_HPP