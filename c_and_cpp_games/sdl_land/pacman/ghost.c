#include <SDL2/SDL.h>
#include "ghost.h"


Ghost *create_ghost() {

    Ghost *s = (Ghost*) malloc(sizeof(Ghost));
    if(s)
        return s;

    return NULL;
}

void init_ghost(SDL_Renderer *r, Ghost *s) {
    SDL_Surface *t = SDL_LoadBMP("pacman.bmp");
    s->sprite = SDL_CreateTextureFromSurface(r, t);
    SDL_FreeSurface(t);
    s->srcRect.x = s->srcRect.y = 0;
    s->srcRect.x = 32;
    s->srcRect.w = s->srcRect.h = 31;
    s->dstRect.x = s->dstRect.y = 0;
    s->dstRect.w = s->dstRect.h = 31;
    s->rect.x = 300;
    s->rect.y = 200;
    s->rect.w = 16;
    s->rect.h = 16;
    s->step = 16;
}



