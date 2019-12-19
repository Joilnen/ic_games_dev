#include <SDL2/SDL.h>
#include "ghost.h"


Ghost *create_ghost() {

    Ghost *s = (Ghost*) malloc(sizeof(Ghost));
    if(s)
        return s;

    return NULL;
}

void init_ghost(SDL_Renderer *r, Ghost *s) {
    s->p.rect.x = 300;
    s->p.rect.y = 200;
    s->p.rect.w = 16;
    s->p.rect.h = 16;
    s->p.step = 16;
}



