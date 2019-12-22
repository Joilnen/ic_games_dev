/**************************
*  Author: Joilnen Leite
**************************/
 
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
#include "sound.h" 

int main()
{
    unsigned int run = 1;
    Uint32 lasttime, nowtime, dt = DT_ELAPSED_LIMIT;

    GameScreen g;
    gamescreen_init(&g);

    Pacman *pacman = create_pacman();
    init_pacman(g.renderer, pacman);

    Ghost *ghost = create_ghost();
    init_ghost(g.renderer, ghost);

    GameMap *map = create_map();
    init_map(g.renderer, map, &g);
    init_sound(map);

    lasttime = nowtime = get_elapsed_time();
    while(run) {
        nowtime += get_elapsed_time();
        SDL_SetRenderDrawColor(g.renderer, 0, 0, 0, 255);
        SDL_RenderClear(g.renderer);
        draw_map(g.renderer, map);
        SDL_RenderPresent(g.renderer);
        get_event(map, &run);
        if(nowtime - lasttime > dt) {
            update_map(map);
            lasttime = nowtime;
        }
    }
    SDL_Quit();

    return 0;
}


