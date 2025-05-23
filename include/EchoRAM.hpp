#ifndef ECHO_RAM_HPP
#define ECHO_RAM_HPP

#include "WorkingRAM.hpp"

class EchoRAM {
public:
    explicit EchoRAM(WorkingRAM* workingRAM) noexcept;

    [[nodiscard]]
    uint8_t read(uint16_t address);

    void write(uint16_t address, uint8_t value);

private:

    static constexpr uint16_t ValueToSubstract{ 0x1000 };

    WorkingRAM* workingRAM_m;

};

#endif // !ECHO_RAM_HPP