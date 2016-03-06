#ifndef MAP_H
#define MAP_H

#include "defs.h"

typedef struct GameMap {
    char *t_map[63];
    unsigned int sz;
} GameMap;

GameMap *create_map();
void init_map(GameMap *);
void draw_map(SDL_Renderer *, GameMap *);

#endif


