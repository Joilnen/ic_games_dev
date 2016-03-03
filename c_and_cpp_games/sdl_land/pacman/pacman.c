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
    s->rect.x = 200;
    s->rect.y = 200;
    s->rect.w = 16;
    s->rect.h = 16;
    s->move = NONE;
    s->step = 16;
}


