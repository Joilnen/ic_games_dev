#include <SDL2/SDL.h>
#include <stdlib.h>
#include "snake.h"
#include "cookie.h"
#include "event.h"
#include "draw.h"
#include "init.h"

Uint32 get_draw_tick(Uint32 i, void *p) {
    printf("Timer wake up\n");
    return 1;
}

int main()
{
    GameScreen g;
    unsigned int run = 1;
    Uint32 currenttime, lasttime;
    currenttime = lasttime = SDL_GetTicks();
    
    gamescreen_init(&g);

    Snake *snake = create_snake();
    init_snake(g.renderer, snake);

    Cookie *cookie = create_cookie();
    init_cookie(g.renderer, cookie);

    // SDL_TimerID id_timer = SDL_AddTimer(5345, get_draw_tick, NULL);

    lasttime = currenttime = SDL_GetTicks();
    lasttime = 1000 * 1000;
    while(run) {
        get_event(snake, &run);
        currenttime += SDL_GetTicks();

        printf("ticks %ul\n", SDL_GetTicks());

        if(SDL_TICKS_PASSED(currenttime, lasttime)) {
            draw_snake(g.renderer, snake);
            draw_cookie(g.renderer, cookie);
            // SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            // SDL_RenderClear(renderer);
            lasttime = currenttime + 10 * 1000;
            SDL_RenderPresent(g.renderer);
            SDL_SetRenderDrawColor(g.renderer, 0, 0, 0, 255);
            SDL_RenderClear(g.renderer);
        }
    }

    SDL_Quit();

    return 0;
}


