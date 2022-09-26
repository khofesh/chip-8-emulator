#ifndef CHIP8STACK_H_INCLUDED
#define CHIP8STACK_H_INCLUDED

#include "config.h"

struct chip8;
struct chip8_stack
{
    // unsigned short is 2 bytes
    unsigned short stack[CHIP8_TOTAL_STACK_DEPTH];
};

void chip8_stack_push(struct chip8 *chip8, unsigned short val);
unsigned short chip8_stack_pop(struct chip8* chip8);

#endif // CHIP8STACK_H_INCLUDED