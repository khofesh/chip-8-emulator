#include <memory.h>
#include <assert.h>

#include "chip8.h"

/* http://devernay.free.fr/hacks/chip8/C8TECH10.HTM#2.4 */
const char chip8_default_character_set[] = {
    // character 0
    0xF0,
    0x90,
    0x90,
    0x90,
    0xF0,
    // character 1
    0x20,
    0x60,
    0x20,
    0x20,
    0x70,
    // character 2
    0xF0,
    0x10,
    0xF0,
    0x80,
    0xF0,
    // character 3
    0xF0,
    0x10,
    0xF0,
    0x10,
    0xF0,
    // character 4
    0x90,
    0x90,
    0xF0,
    0x10,
    0x10,
    // character 5
    0xF0,
    0x80,
    0xF0,
    0x10,
    0xF0,
    // character 6
    0xF0,
    0x80,
    0xF0,
    0x90,
    0xF0,
    // character 7
    0xF0,
    0x10,
    0x20,
    0x40,
    0x40,
    // character 8
    0xF0,
    0x90,
    0xF0,
    0x90,
    0xF0,
    // character 9
    0xF0,
    0x90,
    0xF0,
    0x10,
    0xF0,
    // character A
    0xF0,
    0x90,
    0xF0,
    0x90,
    0x90,
    // character B
    0xE0,
    0x90,
    0xE0,
    0x90,
    0xE0,
    // character C
    0xF0,
    0x80,
    0x80,
    0x80,
    0xF0,
    // character D
    0xE0,
    0x90,
    0x90,
    0x90,
    0xE0,
    // character E
    0xF0,
    0x80,
    0xF0,
    0x80,
    0xF0,
    // character F
    0xF0,
    0x80,
    0xF0,
    0x80,
    0x80,
};

void chip8_init(struct chip8 *chip8)
{
    memset(chip8, 0, sizeof(struct chip8));
    memcpy(&chip8->memory.memory, chip8_default_character_set, sizeof(chip8_default_character_set));
}

void chip8_exec(struct chip8 *chip8, unsigned short opcode)
{
}

void chip8_load(struct chip8 *chip8, const char *buf, size_t size)
{
    assert(size + CHIP8_PROGRAM_LOAD_ADDRESS < CHIP8_MEMORY_SIZE);
    memcpy(&chip8->memory.memory[CHIP8_PROGRAM_LOAD_ADDRESS], buf, size);

    // change program counter
    chip8->registers.PC = CHIP8_PROGRAM_LOAD_ADDRESS;
}