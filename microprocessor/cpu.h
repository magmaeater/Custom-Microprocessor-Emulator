#ifndef CPU_H_INCLUDED
#define CPU_H_INCLUDED

#include "memory.h"


namespace CPU_4001
{
    class cpu
    {
        public:
            const byte reserved_address;
            const byte base_address;

        private:
            byte mprogram_counter;
            byte mregister0;
            byte mregister1;
            bool moverflow;
            bool munderflow;
            bool msign;
            bool mhalt;
            memory* m_thememory;



        public:
            cpu(memory* p_thememory);
            ~cpu();
            void reset();
            void run();
            const byte fetch();
            void decode(const byte& p_theopcode);
            void beep();
            void store();
            void print();

    };

}


#endif // CPU_H_INCLUDED
