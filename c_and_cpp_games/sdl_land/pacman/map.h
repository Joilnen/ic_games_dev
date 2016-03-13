#ifndef MAP_H
#define MAP_H

#include "defs.h"
#include "pacman.h"

typedef struct Pos {
    int x, y;
} Pos;
typedef struct GameMap {
    char *t_map[63];
    unsigned int sz;
    SDL_Texture *wall, *cross,
                *pils, *ghost,
                *special, *pacman;
    enum move move;
    Pos pacman_pos, ghost_pos[32];
    unsigned short ghost_pos_count;
} GameMap;

GameMap *create_map();
void init_map(SDL_Renderer *, GameMap *);
void draw_map(SDL_Renderer *, GameMap *);
void update_map(GameMap *);
void send_event(GameMap *);

#endif


