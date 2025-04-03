#include "TestingMemoryBus.hpp"

TestingMemoryBus::TestingMemoryBus(Cartridge *cartridge, WorkingRAM *workingRAM, HighRAM *highRAM, EchoRAM *echoRAM, VideoRAM *videoRAM) noexcept 
    : MemoryBus{ cartridge, workingRAM, highRAM, echoRAM, videoRAM }
{
}

uint8_t TestingMemoryBus::read(uint16_t address) {
    if (address == LY_Register_Address) {
        return FixedReturnValueFor0xFF44;
    }

    return MemoryBus::read(address);
}
