#ifndef WORKING_RAM_HPP
#define WORKING_RAM_HPP

#include <array>
#include <cstdint>
#include "MemoryMap.hpp"
#include "AddressMaper.hpp"

class WorkingRAM : public AddressMapper<Work_RAM_Start_Address, Work_RAM_End_Address> {
};

#endif // !WORKING_RAM_HPP