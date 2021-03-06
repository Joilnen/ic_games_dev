#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pacman.h"
#include "map.h"
#include "poslist.h"
#include "update.h"

GameMap *create_map() {

    GameMap *m = (GameMap*) malloc(sizeof(GameMap));

    if (!m)
        return NULL;

    return m;
}

static void init_map_player(SDL_Renderer *r, GameMap *m) {

    SDL_Surface *t = SDL_LoadBMP("pacman.bmp");
    m->p.p.sprite = SDL_CreateTextureFromSurface(r, t);
    SDL_FreeSurface(t);
    m->p.p.srcRect.x = m->p.p.srcRect.y = 0;
    m->p.p.srcRect.x = 32;
    m->p.p.srcRect.w = m->p.p.srcRect.h = 31;
    m->p.p.dstRect.x = m->p.p.dstRect.y = 0;
    m->p.p.dstRect.w = m->p.p.dstRect.h = 31;
    m->p.p.step = 16;
    m->p.p.move = NONE;
}

static void init_map_ghost(SDL_Renderer *r, GameMap *m) {

    SDL_Surface *t = SDL_LoadBMP("ghost.bmp");
    int i;

    for (i = 0; i < m->ghost_counter; i++)
        m->g[i].p.sprite = SDL_CreateTextureFromSurface(r, t);

    SDL_FreeSurface(t);
}

void init_map(SDL_Renderer *r, GameMap *m, GameScreen *screen) {

    FILE *f = NULL;
    char line[MAX_MAP_LINE_SZ];
    unsigned int l = 0;
    SDL_Surface *s = NULL;
    unsigned short int count;
    char *tmp = NULL;

    m->ghost_counter = 5;
    if (!(f = fopen("mapmodel.txt", "r")))
        exit(-1);

    while (fgets(line, MAX_MAP_LINE_SZ, f)) {
        m->t_map[l] = (char*) malloc(sizeof(char) * MAX_MAP_LINE_SZ);
        printf("%s\n", line);
        if (!strchr(line, ';') && !strchr(line, '=')) {
            if(tmp = index(line, '\n'))
                *tmp = '\0';
            strcpy(m->t_map[l++], line);
        }
        else if (strchr(line, '=')) {
            char tmp[MAX_GHOST_COUNTER_SZ];
            unsigned short s;

            if(strlen(line) - 1 > MAX_GHOST_COUNTER_SZ)
                exit(-1);
            strcpy(tmp, line + 1);
            m->ghost_counter = atoi(tmp);
        }
    }

    fclose(f);

    if (l)
        m->sz = l;

    for (count = 0; count < l; count ++)
         printf("%s\n", m->t_map[count]);

    s = SDL_LoadBMP("wall_h.bmp");
    if (s == NULL)
        exit(-1);
    m->wall = SDL_CreateTextureFromSurface(r, s);
    SDL_FreeSurface(s);
    s = SDL_LoadBMP("wall_x.bmp");
    if (s == NULL)
        exit(-1);
    m->cross = SDL_CreateTextureFromSurface(r, s);
    s = SDL_LoadBMP("ghost.bmp");
    if (s == NULL)
        exit(-1);
    m->g[0].p.sprite = SDL_CreateTextureFromSurface(r, s);
    SDL_FreeSurface(s);
    s = SDL_LoadBMP("special.bmp");
    if (s == NULL)
        exit(-1);
    m->special = SDL_CreateTextureFromSurface(r, s);
    s = SDL_LoadBMP("pils1.bmp");
    if (s == NULL)
        exit(-1);
    m->pils = SDL_CreateTextureFromSurface(r, s);
    s = SDL_LoadBMP("pils.bmp");
    if (s == NULL)
        exit(-1);
    m->big_pils = SDL_CreateTextureFromSurface(r, s);
    SDL_FreeSurface(s);

    init_map_player(r, m);
    init_map_ghost(r, m);

    m->score_counter = 0;
}

void update_map(GameMap *m) {

    update(m);
    if (m->p.p.move != NONE)
        m->p.p.srcRect.x = (m->p.p.srcRect.x)? 0: 32;
}


