#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>

int main(int argc, char* argv[]) 
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) 
    {
        fprintf(stderr, "Не удалось запустить SDL: %s\n", SDL_GetError());

        return 1;
    }

    SDL_Surface* screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);

    if (screen == NULL) 
    {
        fprintf(stderr, "Не удалось установить видеорежим: %s\n", SDL_GetError());
        SDL_Quit();

        return 1;
    }

    SDL_WM_SetCaption("SDL 1.2.15 Test (2026)", NULL);

    bool running = true;
    SDL_Event event;

    while (running) 
    {
        while (SDL_PollEvent(&event)) 
        {
            if (event.type == SDL_QUIT) 
            {
                running = false;
            }

            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    running = false;
                }
            }
        }

        if (screen) 
        {
            Uint32 blue = SDL_MapRGB(screen->format, 0, 100, 200);
            SDL_FillRect(screen, NULL, blue);
            SDL_Flip(screen);
        }

        SDL_Delay(16);
    }

    SDL_Quit();

    return 0;
}