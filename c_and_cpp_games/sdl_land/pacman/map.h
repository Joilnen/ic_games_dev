#ifndef MAP_H
#define MAP_H

#include "defs.h"
#include "pacman.h"
#include "ghost.h"

typedef struct Pos {
    int x, y;
} Pos;
typedef struct GameMap {
    char *t_map[63];
    unsigned int sz;
    SDL_Texture *wall, *cross,
                *pils, *big_pils, *ghost,
                *special, *pacman;
    enum move move;
    Pos pacman_pos, ghost_pos[32];
    unsigned short ghost_pos_count;
    Pacman p;
    Ghost g[32];
} GameMap;

GameMap *create_map();
void init_map(SDL_Renderer *, GameMap *);
void draw_map(SDL_Renderer *, GameMap *);
void update_map(GameMap *);
void send_event(GameMap *);
void move_player(GameMap *m);
void move_ghost(GameMap *m);
void draw_map_player(SDL_Renderer *r, GameMap *m);
void draw_map_ghost(SDL_Renderer *r, GameMap *m);

#endif


