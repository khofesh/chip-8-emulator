#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED

/*
    The Chip-8 language is capable of accessing up
    to 4KB (4,096 bytes) of RAM, from location 0x000 (0)
    to 0xFFF (4095). The first 512 bytes, from 0x000 to 0x1FF,
    are where the original interpreter was located,
    and should not be used by programs.
*/
#define CHIP8_MEMORY_SIZE 4096
/*
    0x200 (512) Start of most Chip-8 programs
*/
#define CHIP8_PROGRAM_LOAD_ADDRESS 0x200
/*
    The original implementation of the Chip-8 language
    used a 64x32-pixel monochrome display with this format:
*/
#define CHIP8_WIDTH 64
#define CHIP8_HEIGHT 32
#define EMULATOR_WINDOW_TITLE "Chip8 Emulator"
#define CHIP8_WINDOW_MULTIPLIER 10

// register
#define CHIP8_TOTAL_DATA_REGISTERS 16

// stack
#define CHIP8_TOTAL_STACK_DEPTH 16

// keyboard
#define CHIP8_TOTAL_KEYS 16

/*
    The data should be stored in the interpreter area of Chip-8 memory (0x000 to 0x1FF).
*/
// character set
#define CHIP8_CHARACTER_SET_LOAD_ADDRESS 0x00

#define CHIP8_DEFAULT_SPRITE_HEIGHT 5

#endif // CONFIG_H_INCLUDED