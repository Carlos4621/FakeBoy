#pragma once
#ifndef TESTING_MEMORY_BUS_HPP
#define TESTING_MEMORY_BUS_HPP

#include <fstream>
#include "MemoryBus.hpp"

class TestingMemoryBus : public MemoryBus {
public:
    
    TestingMemoryBus(Cartridge* cartridge, WorkingRAM* workingRAM, HighRAM* highRAM, EchoRAM* echoRAM, VideoRAM* videoRAM) noexcept;

    [[nodiscard]]
    uint8_t read(uint16_t address);

private:
    static constexpr uint8_t FixedReturnValueFor0xFF44{ 0x90 };

};

#endif // !TESTING_MEMORY_BUS_HPP