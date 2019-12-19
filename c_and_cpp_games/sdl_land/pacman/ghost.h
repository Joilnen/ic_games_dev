#ifndef GOST_H
#define GOST_H

#include "sprite.h"

typedef struct Ghost {
    struct Sprite p;
} Ghost;

Ghost *create_ghost();
void delete_ghost(Ghost *s);
void init_ghost(SDL_Renderer *r, Ghost *);

#endif
