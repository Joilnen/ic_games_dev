#ifndef MAP_H
#define MAP_H

#include "defs.h"

typedef struct GameMap {
    char *t_map[63];
    unsigned int sz;
    SDL_Texture *wall, *cross;
} GameMap;

GameMap *create_map();
void init_map(SDL_Renderer *, GameMap *);
void draw_map(SDL_Renderer *, GameMap *);

#endif


