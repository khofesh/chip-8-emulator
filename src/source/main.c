#include <stdio.h>
#include <SDL2/SDL.h>

#include "chip8.h"

int main(int argc, char *argv[])
{
    // chip8 interpreter
    struct chip8 chip8;
    chip8_memory_set(&chip8.memory, 0x400, 'Z');
    // check the memory
    // printf("%c\n", chip8_memory_get(&chip8.memory, 0x400));

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = SDL_CreateWindow(
        EMULATOR_WINDOW_TITLE, 
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        CHIP8_WIDTH * CHIP8_WINDOW_MULTIPLIER,
        CHIP8_HEIGHT * CHIP8_WINDOW_MULTIPLIER, 
        SDL_WINDOW_SHOWN
    );

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_TEXTUREACCESS_TARGET);

    while (1)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            /* if click x button */
            if (event.type == SDL_QUIT)
            {
                goto out;
            }
        }        

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
        SDL_Rect r;
        r.x = 0;
        r.y = 0;
        r.w = 40;
        r.h = 40;

        SDL_RenderFillRect(renderer, &r);

        SDL_RenderPresent(renderer);
    }
    
    /* out */
    out: 
    SDL_DestroyWindow(window);

    return 0;
}
