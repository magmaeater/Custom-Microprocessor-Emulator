#include "memory.h"
#include <iostream>

namespace CPU_4001
{


memory::memory():max_address(255),memory_space(new byte[max_address])
{
    clear_mem();

}

memory::~memory()
{
    if(memory_space != nullptr)
    {
        delete[] memory_space;
        memory_space = nullptr;

    }

}

void memory::clear_mem()
{
    for(byte i = 0; i < max_address; ++i)
    {
        memory_space[i] = 0;

    }

}

const byte& memory::read(const byte& p_address)
{
    return memory_space[p_address];
}

void memory::write(const byte& p_address, const byte& p_value)
{
    memory_space[p_address] = p_value;

}

}

