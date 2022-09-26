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
    The original implementation of the Chip-8 language 
    used a 64x32-pixel monochrome display with this format:
*/
#define CHIP8_WIDTH 64
#define CHIP8_HEIGHT 32
#define EMULATOR_WINDOW_TITLE "Chip8 Emulator"
#define CHIP8_WINDOW_MULTIPLIER 10

// register
#define CHIP8_TOTAL_DATA_REGISTERS 16


#endif // CONFIG_H_INCLUDED