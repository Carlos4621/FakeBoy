#ifndef VIDEO_RAM_HPP
#define VIDEO_RAM_HPP

#include "AddressMaper.hpp"
#include "MemoryMap.hpp"

class VideoRAM : public AddressMapper<VRAM_Start_Address, VRAM_End_Address> {
};


#endif // !VIDEO_RAM_HPP