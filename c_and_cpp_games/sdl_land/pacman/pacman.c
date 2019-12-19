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
    s->p.sprite = SDL_CreateTextureFromSurface(r, t);
    SDL_FreeSurface(t);
    s->p.srcRect.x = s->p.srcRect.y = 0;
    s->p.srcRect.x = 32;
    s->p.srcRect.w = s->p.srcRect.h = 31;
    s->p.dstRect.x = s->p.dstRect.y = 0;
    s->p.dstRect.w = s->p.dstRect.h = 31;
    s->p.step = 16;
    s->p.move = LEFT;
}


