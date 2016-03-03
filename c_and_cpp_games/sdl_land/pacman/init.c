#include "init.h"

void gamescreen_init(GameScreen *g) {
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER))
        exit(-1);
    atexit(SDL_Quit);

    g->window = SDL_CreateWindow("Snake",
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            480, 480, SDL_WINDOW_SHOWN);

    if(!g->window)
        exit(-1);
    else
        g->renderer = SDL_CreateRenderer(g->window, -1, 0);
    if(!g->renderer)
        exit(-1);
    SDL_SetRenderDrawColor(g->renderer, 0, 0, 0, 255);

    SDL_RenderClear(g->renderer);
    SDL_RenderPresent(g->renderer);
}

