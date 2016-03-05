#ifndef MAP_H
#define MAP_H

#include "defs.h"

typedef struct GameMap {
    char **txt_map_ref;
} GameMap;

GameMap *create_map();
void init_map(GameMap *);

#endif

