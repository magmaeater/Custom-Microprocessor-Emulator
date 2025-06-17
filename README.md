# Custom-Microprocessor-Emulator

Microprocessor Emulator
This project is a simple emulator for a hypothetical microprocessor, written in C++. It simulates basic CPU and memory operations, allowing you to load and execute a small set of machine instructions.

Features
Memory Management:
The CPU_4001::memory class provides a byte-addressable memory space with read, write, and clear operations.

CPU Simulation:
The CPU_4001::cpu class simulates a basic CPU with registers, a program counter, and support for simple instructions like load, add, store, print, beep, and halt.

Instruction Set:

0: Halt
1: Load value into register 0
2: Load value into register 1
3: Add register 1 to register 0
4: Beep
5: Store register 0 to memory
6: Print value from memory
Example Program:
The main.cpp file demonstrates how to initialize memory, load a program, and run the CPU.

File Structure
main.cpp: Entry point, loads instructions and runs the CPU.
cpu.h, cpu.cpp: CPU class and implementation.
memory.h, memory.cpp: Memory class and implementation.
Building
You can build the project using g++:

Or use the provided VS Code task for building.

Usage
Run the compiled executable:

You will see the memory initialization, program execution, and final memory state.

License
This project is for educational purposes.

