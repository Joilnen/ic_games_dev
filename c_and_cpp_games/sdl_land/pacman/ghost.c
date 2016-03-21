#include <SDL2/SDL.h>
#include "ghost.h"


Ghost *create_ghost() {

    Ghost *s = (Ghost*) malloc(sizeof(Ghost));
    if(s)
        return s;

    return NULL;
}

void init_ghost(SDL_Renderer *r, Ghost *s) {
    s->rect.x = 300;
    s->rect.y = 200;
    s->rect.w = 16;
    s->rect.h = 16;
    s->step = 16;
}




