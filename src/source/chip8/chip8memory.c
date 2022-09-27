#include <assert.h>
#include <stdio.h>

#include "chip8memory.h"

static void chip8_is_memory_in_bounds(int index)
{
    // printf("index: %d \n", index);
    // you could handle it gracefully, instead of this
    assert(index >= 0 && index < CHIP8_MEMORY_SIZE);
}

void chip8_memory_set(struct chip8_memory *memory, int index, unsigned char val)
{
    chip8_is_memory_in_bounds(index);

    memory->memory[index] = val;
}

unsigned char chip8_memory_get(struct chip8_memory *memory, int index)
{
    chip8_is_memory_in_bounds(index);

    return memory->memory[index];
}

unsigned short chip8_memory_get_short(struct chip8_memory *memory, int index)
{
    unsigned char byte1 = chip8_memory_get(memory, index);
    unsigned char byte2 = chip8_memory_get(memory, index + 1);

    // read 2 bytes at a time from memory
    return byte1 << 8 | byte2;
}