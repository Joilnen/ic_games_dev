#include <SDL2/SDL.h>
#include <stdlib.h>
#include "pacman.h"
#include "gost.h"
#include "event.h"
#include "draw.h"
#include "init.h"
#include "update.h"
#include "timer.h"
#include "defs.h"

Uint32 get_draw_tick(Uint32 i, void *p) {
    printf("Timer wake up\n");
    return 1;
}

int main()
{
    GameScreen g;
    unsigned int run = 1;
    Uint32 lasttime, nowtime, dt = DT_ELAPSED_LIMIT;

    gamescreen_init(&g);

    Pacman *pacman = create_pacman();
    init_pacman(g.renderer, pacman);

    Gost *gost = create_gost();
    init_gost(g.renderer, gost);

    // SDL_TimerID id_timer = SDL_AddTimer(5345, get_draw_tick, NULL);

    lasttime = nowtime = get_elapsed_time();
    while(run) {
        nowtime += get_elapsed_time();
        get_event(pacman, &run);
        if(nowtime - lasttime > dt) {
            update(g.renderer, pacman);
            lasttime = nowtime;
        }
        draw_pacman(g.renderer, pacman);
        draw_gost(g.renderer, gost);
        // SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        // SDL_RenderClear(renderer);
        SDL_RenderPresent(g.renderer);
        SDL_SetRenderDrawColor(g.renderer, 0, 0, 0, 255);
        SDL_RenderClear(g.renderer);
    }

    SDL_Quit();

    return 0;
}


