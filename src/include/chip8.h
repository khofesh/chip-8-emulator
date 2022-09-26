#ifndef CHIP8_H_INCLUDED
#define CHIP8_H_INCLUDED

#include "config.h"
#include "chip8memory.h"
#include "chip8register.h"
#include "chip8stack.h"
#include "chip8keyboard.h"

struct chip8
{
    struct chip8_memory memory;
    struct chip8_registers registers;
    struct chip8_stack stack;
    struct chip8_keyboard keyboard;
};

#endif // CHIP8_H_INCLUDED