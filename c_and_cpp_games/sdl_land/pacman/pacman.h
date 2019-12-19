#ifndef PACMAN_H
#define PACMAN_H

#include <SDL2/SDL.h>
#include "sprite.h"


typedef struct Pacman {
    Sprite p;
} Pacman;

Pacman *create_pacman();
void delete_snake(Pacman *s);
void init_snake(SDL_Renderer *r, Pacman *);
void init_pacman(SDL_Renderer *r, Pacman *s);

#endif


