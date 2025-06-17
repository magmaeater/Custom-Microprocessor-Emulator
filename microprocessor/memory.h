#ifndef cpu_memory
#define cpu_memory


namespace CPU_4001
{

typedef unsigned char byte;

class memory
{
public:

    const byte max_address;

private:
    byte* memory_space;

public:
    //construct memory class instance and clear memory
    memory();
    //destruct memory class instance and release allocated mem space
    ~memory();
    //clear all memory values back to 0
    void clear_mem();
    //func to read provided address val
    const byte& read(const byte& p_address);
    //func to write to certain address val
    void write(const byte& p_address, const byte& p_value);

};

}

#endif // cpu_memory
