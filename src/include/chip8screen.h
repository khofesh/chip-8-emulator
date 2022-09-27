#ifndef CHIP8SCREEN_H_INCLUDED
#define CHIP8SCREEN_H_INCLUDED

#include <stdbool.h>
#include "config.h"

struct chip8_screen
{
    bool pixels[CHIP8_HEIGHT][CHIP8_WIDTH];
};

void chip8_screen_set(struct chip8_screen *screen, int x, int y);
bool chip8_screen_is_set(struct chip8_screen *screen, int x, int y);
/* I change the "const char *sprite" to "unsigned char *sprite", to satisfy gcc */
bool chip8_screen_draw_sprite(struct chip8_screen *screen, int x, int y, unsigned char *sprite, int num);
void chip8_screen_clear(struct chip8_screen *screen);

#endif // CHIP8SCREEN_H_INCLUDED