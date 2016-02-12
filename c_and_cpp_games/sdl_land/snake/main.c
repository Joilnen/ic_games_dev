#include <SDL2/SDL.h>
#include <stdlib.h>
#include "snake.h"
#include "cookie.h"

void game_exit() {
    SDL_Quit();
}

void get_event(unsigned int *r) {

    SDL_Event e;

    if(SDL_PollEvent(&e)) {
        if(e.type == SDL_QUIT)
            *r = 0;
        if(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)
            *r = 0;
    }
}

int main()
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    unsigned int run = 1;

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

    Snake *snake = create_snake();
    init_body(renderer, snake);


    Cookie *cookie = create_cookie();
    init_cookie(renderer, cookie);

    while(run) {
        draw_snake(renderer, snake);
        draw_cookie(renderer, cookie);
        get_event(&run);
        // SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        // SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    SDL_Quit();

    return 0;
}


