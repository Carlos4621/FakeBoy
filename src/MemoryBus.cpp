#include "MemoryBus.hpp"

MemoryBus::MemoryBus(Cartridge *cartridge, WorkingRAM *workingRAM, HighRAM *highRAM, EchoRAM *echoRAM, VideoRAM *videoRAM) noexcept 
    : cartridge_m{ cartridge }
    , workingRAM_m{ workingRAM }
    , highRAM_m{ highRAM }
    , echoRAM_m{ echoRAM }
    , videoRAM_m{ videoRAM }
{
}

void MemoryBus::write(uint16_t address, uint8_t value)
{
    switch (determineMemoryRange(address)) {
    case MemoryRange::Bank_0:
    case MemoryRange::SwitchableROMBanks:
    case MemoryRange::ExternalRAM:
        cartridge_m->write(address, value);
        break;

    case MemoryRange::High_RAM:
        highRAM_m->write(address, value);
        break;

    case MemoryRange::Work_RAM:
        workingRAM_m->write(address, value);
        break;

    case MemoryRange::Echo_RAM:
        echoRAM_m->write(address, value);
        break;

    case MemoryRange::VRAM:
        videoRAM_m->write(address, value);
        break;

    default:
        //TODO: Implement the rest of the memory ranges
        break;
    }
}

uint8_t MemoryBus::read(uint16_t address) {
    switch (determineMemoryRange(address)) {
    case MemoryRange::Bank_0:
    case MemoryRange::SwitchableROMBanks:
    case MemoryRange::ExternalRAM:
        return cartridge_m->read(address);
        break;

    case MemoryRange::High_RAM:
        return highRAM_m->read(address);
        break;

    case MemoryRange::Work_RAM:
        return workingRAM_m->read(address);
        break;

    case MemoryRange::Echo_RAM:
        return echoRAM_m->read(address);
        break;

    case MemoryRange::VRAM:
        return videoRAM_m->read(address);
        break;

    default:
        // TODO: Implement the rest of the memory ranges
        return 0;
        break;
    }
}
