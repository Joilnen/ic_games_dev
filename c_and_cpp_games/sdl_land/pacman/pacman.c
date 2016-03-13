#include <SDL2/SDL.h>
#include "pacman.h"

Pacman *create_pacman() {
    Pacman *s = (Pacman*) malloc(sizeof(Pacman));
    if(s)
        return s;

    return NULL;
}

void delete_pacman(Pacman *s) {

}

void init_pacman(SDL_Renderer *r, Pacman *s) {
    SDL_Surface *t = SDL_LoadBMP("pacman.bmp");
    s->sprite = SDL_CreateTextureFromSurface(r, t);
    SDL_FreeSurface(t);
    s->srcRect.x = s->srcRect.y = 0;
    s->srcRect.x = 32;
    s->srcRect.w = s->srcRect.h = 31;
    s->dstRect.x = s->dstRect.y = 0;
    s->dstRect.w = s->dstRect.h = 31;
    s->step = 16;
    s->move = LEFT;
}


