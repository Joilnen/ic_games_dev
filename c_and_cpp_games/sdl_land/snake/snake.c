#include <SDL2/SDL.h>
#include <stdlib.h>

int main()
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER))
        exit(-1);
    atexit(SDL_Quit);

    window = SDL_CreateWindow("Snake",
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            480, 480, SDL_WINDOW_SHOWN);

    if(!window)
        exit(-1);
    else
        renderer = SDL_CreateRenderer(window, -1, 0);
    if(!renderer)
        exit(-1);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(5000);
    SDL_Quit();

    return 0;
}


