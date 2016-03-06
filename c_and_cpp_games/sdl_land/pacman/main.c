#include <SDL2/SDL.h>
#include <stdlib.h>
#include "map.h"
#include "pacman.h"
#include "ghost.h"
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

    Ghost *ghost = create_ghost();
    init_ghost(g.renderer, ghost);

    GameMap *map = create_map();
    init_map(map);

    // SDL_TimerID id_timer = SDL_AddTimer(5345, get_draw_tick, NULL);

    lasttime = nowtime = get_elapsed_time();
    while(run) {
        nowtime += get_elapsed_time();
        draw_map(g.renderer, map);
        draw_pacman(g.renderer, pacman);
        draw_ghost(g.renderer, ghost);
        SDL_RenderPresent(g.renderer);
        SDL_SetRenderDrawColor(g.renderer, 0, 0, 0, 255);
        SDL_RenderClear(g.renderer);
        get_event(pacman, &run);
        if(nowtime - lasttime > dt) {
            update(g.renderer, pacman, ghost);
            lasttime = nowtime;
        }
    }

    SDL_Quit();

    return 0;
}


