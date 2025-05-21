#include "EchoRAM.hpp"

EchoRAM::EchoRAM(WorkingRAM *workingRAM) noexcept
    : workingRAM_m{ workingRAM }
{
}

uint8_t EchoRAM::read(uint16_t address) {
    const auto redirectionedAddress{ address - ValueToSubstract };

    return workingRAM_m->read(redirectionedAddress);
}

void EchoRAM::write(uint16_t address, uint8_t value) {
    const auto redirectionedAddress{ address - ValueToSubstract };

    workingRAM_m->write(redirectionedAddress, value);
}
