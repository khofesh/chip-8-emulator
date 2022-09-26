#ifndef CHIP8REGISTERS_H_INCLUDED
#define CHIP8REGISTERS_H_INCLUDED

#include "config.h"

/*
    Chip-8 has 16 general purpose 8-bit registers, usually referred to as Vx, 
    where x is a hexadecimal digit (0 through F). There is also a 16-bit 
    register called I. This register is generally used to store memory addresses, 
    so only the lowest (rightmost) 12 bits are usually used.

    Chip-8 also has two special purpose 8-bit registers, for the delay and sound timers. 
    When these registers are non-zero, they are automatically decremented at a rate of 60Hz.

    There are also some "pseudo-registers" which are not accessable from Chip-8 programs. 
    The program counter (PC) should be 16-bit, and is used to store the currently executing address. 
    The stack pointer (SP) can be 8-bit, it is used to point to the topmost level of the stack.
*/
struct chip8_registers
{
    unsigned char V[CHIP8_TOTAL_DATA_REGISTERS];
    unsigned short I;
    unsigned char delay_timer;
    unsigned char sound_timer;
    unsigned short PC;
    unsigned char SP;
};


#endif // CHIP8REGISTERS_H_INCLUDED