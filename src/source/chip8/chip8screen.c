#include <assert.h>

#include "chip8.h"

static void chip8_screen_check_bounds(int x, int y)
{
    assert(x >= 0 && x < CHIP8_WIDTH && y >= 0 && y < CHIP8_HEIGHT);
}

void chip8_screen_set(struct chip8_screen *screen, int x, int y)
{
    chip8_screen_check_bounds(x, y);
    screen->pixels[y][x] = true;
}

bool chip8_screen_is_set(struct chip8_screen *screen, int x, int y)
{
    chip8_screen_check_bounds(x, y);
    return screen->pixels[y][x];
}

bool chip8_screen_draw_sprite(struct chip8_screen *screen, int x, int y, unsigned char *sprite, int num)
{
    bool pixel_collision = false;

    for (int ly = 0; ly < num; ly++)
    {
        char c = sprite[ly];
        for (int lx = 0; lx < 8; lx++)
        {
            // shift the bit to the right
            // if it's zero, no pixel is set, skip to the next
            // because there's nothing to draw
            if ((c & (0b10000000 >> lx)) == 0)
            {
                continue;
            }

            if (screen->pixels[(ly + y) % CHIP8_HEIGHT][(lx + x) % CHIP8_WIDTH])
            {
                pixel_collision = true;
            }

            screen->pixels[(ly + y) % CHIP8_HEIGHT][(lx + x) % CHIP8_WIDTH] ^= true;
        }
    }

    return pixel_collision;
}