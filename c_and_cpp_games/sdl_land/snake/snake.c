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
    SDL_Event e;
    while(1) {
        if(SDL_PollEvent(&e)) {
            if(e.type == SDL_QUIT)
                break;
            if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)
                break;
        }
    }
    SDL_Quit();

    return 0;
}


