#ifndef CHIP8_H_INCLUDED
#define CHIP8_H_INCLUDED

#include "config.h"
#include "chip8memory.h"
#include "chip8register.h"
#include "chip8stack.h"

struct chip8
{
    struct chip8_memory memory;
    struct chip8_registers registers;
    struct chip8_stack stack;
};

#endif // CHIP8_H_INCLUDED