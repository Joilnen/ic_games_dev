#include <SDL2/SDL.h>
#include "gost.h"


Gost *create_gost() {

    Gost *s = (Gost*) malloc(sizeof(Gost));
    if(s)
        return s;

    return NULL;
}

void init_gost(SDL_Renderer *r, Gost *s) {
    s->rect.x = 300;
    s->rect.y = 200;
    s->rect.w = 16;
    s->rect.h = 16;
}

void draw_gost(SDL_Renderer *r, Gost *s) {
    SDL_SetRenderDrawColor(r, 255, 255, 0, 255);
    SDL_RenderFillRect(r, &s->rect);
}


