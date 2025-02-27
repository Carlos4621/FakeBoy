#pragma once
#ifndef MEMORY_BUS_HPP
#define MEMORY_BUS_HPP

#include "Cartridge.hpp"
#include "WorkingRam.hpp"
#include "HighRAM.hpp"
#include "EchoRAM.hpp"
#include "VideoRAM.hpp"

class MemoryBus {
public:
    
    MemoryBus(Cartridge* cartridge, WorkingRAM* workingRAM, HighRAM* highRAM, EchoRAM* echoRAM, VideoRAM* videoRAM) noexcept;

    void write(uint16_t address, uint8_t value);
    
    [[nodiscard]]
    uint8_t read(uint16_t address);

private:

    Cartridge* cartridge_m;
    WorkingRAM* workingRAM_m;
    HighRAM* highRAM_m;
    EchoRAM* echoRAM_m;
    VideoRAM* videoRAM_m;

};

#endif // !MEMORY_BUS_HPP