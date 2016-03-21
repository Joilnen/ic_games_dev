#ifndef MAP_H
#define MAP_H

#include "defs.h"
#include "pacman.h"
#include "ghost.h"
#include "init.h"

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
    Pos pacman_pos, ghost_pos[MAX_GHOST_COUNTER_SZ], ghost_born_pos;
    unsigned short ghost_pos_count;
    Pacman p;
    Ghost g[MAX_GHOST_COUNTER_SZ];
    unsigned short ghost_counter;
    unsigned short score_counter;
    GameScreen *screen;
} GameMap;

GameMap *create_map();
void init_map(SDL_Renderer *, GameMap *, GameScreen *);
void draw_map(SDL_Renderer *, GameMap *);
void update_map(GameMap *);
void send_event(GameMap *);
void draw_map_player(SDL_Renderer *r, GameMap *m);
void draw_map_ghost(SDL_Renderer *r, GameMap *m);
unsigned short check_colide_player(GameMap *, enum move);

#endif


