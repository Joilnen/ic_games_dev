#include <SDL2/SDL.h>
#include <stdlib.h>
#include "snake.h"
#include "cookie.h"
#include "event.h"
#include "draw.h"

Uint32 get_draw_tick(Uint32 i, void *p) {
    printf("Timer wake up\n");
    return 1;
}

int main()
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    unsigned int run = 1;
    Uint32 currenttime, lasttime;
    currenttime = lasttime = SDL_GetTicks();

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
    init_snake(renderer, snake);

    Cookie *cookie = create_cookie();
    init_cookie(renderer, cookie);

    // SDL_TimerID id_timer = SDL_AddTimer(5345, get_draw_tick, NULL);

    while(run) {
        currenttime += SDL_GetTicks();

        get_event(snake, &run);
        if(currenttime - lasttime > 400000) {
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);
            draw_snake(renderer, snake);
            draw_cookie(renderer, cookie);
            // SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            // SDL_RenderClear(renderer);
            lasttime = currenttime;
        }
        SDL_RenderPresent(renderer);
    }

    SDL_Quit();

    return 0;
}


