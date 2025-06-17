#include "cpu.h"
#include <iostream>

namespace CPU_4001
{
    cpu::cpu(memory* p_thememory):
        reserved_address(0),
        base_address(1),
        mprogram_counter(base_address),
        mregister0(0),
        mregister1(0),
        moverflow(false),
        munderflow(false),
        msign(false),
        m_thememory(p_thememory),
        mhalt(false)
        {

        }

    cpu::~cpu()
    {
        m_thememory = nullptr;
    }
    void cpu::reset()
    {
        mprogram_counter = 0;
        moverflow = false;
        munderflow = false;
        msign = false;
        mhalt = false;
    }

    void cpu::run()
    {
        //if theres 0, it means HALT instruction
        while(!mhalt)
        {
            m_thememory->write(reserved_address, fetch());
            decode(m_thememory->read(reserved_address));

        }
    }

    void cpu::beep()
    {
        std::cout << '\a';
    }

    void cpu::store()
    {
        mregister1 = m_thememory->read(mprogram_counter);
        ++mprogram_counter;
        m_thememory->write(mregister1, mregister0);
    }

    void cpu::print()
    {
        mregister1 = m_thememory->read(mprogram_counter);
        ++mprogram_counter;
        mregister0 = m_thememory->read(mregister1);
        std::cout << (int)mregister0 << std::endl;

    }

    const byte cpu::fetch()
    {
        byte l_opcode = 0;
        l_opcode = m_thememory->read(mprogram_counter);
        ++mprogram_counter;
        return l_opcode;
    }

    void cpu::decode(const byte& p_theopcode)
    {
        switch(p_theopcode)
        {
        //halt processor
        case 0:
            mhalt = true;
            break;
        //write to register 0 whatever is at program counter position
        case 1:
            mregister0 = m_thememory->read(mprogram_counter);
            ++mprogram_counter;
            break;
        //write to register 1 whatever is at program counter position
        case 2:
            mregister1 = m_thememory->read(mprogram_counter);
            ++mprogram_counter;
            break;
        //add
        case 3:
            mregister0 = mregister1 + mregister0;
            break;
        //beep
        case 4:
            beep();
            break;
        case 5:
            store();
            break;
        case 6:
            print();
            break;

        }

    }

}
