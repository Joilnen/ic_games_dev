#include <SDL2/SDL.h>
#include <stdlib.h>
#include "pacman.h"
#include "gost.h"
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

    Pacman *pacman = create_pacman();
    init_pacman(g.renderer, pacman);

    Gost *gost = create_gost();
    init_gost(g.renderer, gost);

    // SDL_TimerID id_timer = SDL_AddTimer(5345, get_draw_tick, NULL);

    lasttime = currenttime = SDL_GetTicks();
    lasttime = 1000 * 1000;
    while(run) {
        get_event(pacman, &run);
        currenttime += SDL_GetTicks();

        printf("ticks %ul\n", SDL_GetTicks());

        if(SDL_TICKS_PASSED(currenttime, lasttime)) {
            draw_pacman(g.renderer, pacman);
            draw_gost(g.renderer, gost);
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


