#include <iostream>
#include "memory.h"
#include "memory.cpp"
#include "cpu.h"
#include "cpu.cpp"

using namespace std;
using namespace CPU_4001;

int main()
{
    cout << "initializing memory..... ";
    memory* the_memory = new memory();
    cout << "ready" << endl;

    cout << "memory size " << (int)the_memory->max_address << endl;

    cout << "adding machine code.. " << endl;
    //load0 value 1
    the_memory->write(1,1);
    the_memory->write(2,3);
    //load1 value 2
    the_memory->write(3,2);
    the_memory->write(4,2);
    //add
    the_memory->write(5,3);
    //store to 12
    the_memory->write(6,5);
    the_memory->write(7,12);
    //print from 12
    the_memory->write(8,6);
    the_memory->write(9,12);
    //beep
    the_memory->write(10,4);
    //halt
    the_memory->write(11,0);

    for(uint8_t current_address = 0; current_address < (int)the_memory->max_address; ++current_address)
    {
        cout << "address [" << (int)current_address << "] " << "value [" << (int)the_memory->read(current_address) << "]" << endl;

    }

    cout << "creating cpu..." << endl;
    cpu* the_cpu = new cpu(the_memory);
    cout << "cpu ready" << endl;

    cout << "starting..." << endl;
    the_cpu->run();
    cout << "complete..." << endl;

    cout << "final memory state: " << endl;

    for(uint8_t current_address = 0; current_address < (int)the_memory->max_address; ++current_address)
    {
        cout << "address [" << (int)current_address << "] " << "value [" << (int)the_memory->read(current_address) << "]" << endl;

    }


    delete the_cpu;

    delete the_memory;


}
