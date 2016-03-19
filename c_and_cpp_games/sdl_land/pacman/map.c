#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pacman.h"
#include "map.h"

GameMap *create_map() {
    GameMap *m = (GameMap*) malloc(sizeof(GameMap));
    if(!m)
        return NULL;
    return m;
}

static void parsing_map() {

}

static void init_map_player(SDL_Renderer *r, GameMap *m) {
    SDL_Surface *t = SDL_LoadBMP("pacman.bmp");
    m->p.sprite = SDL_CreateTextureFromSurface(r, t);
    SDL_FreeSurface(t);
    m->p.srcRect.x = m->p.srcRect.y = 0;
    m->p.srcRect.x = 32;
    m->p.srcRect.w = m->p.srcRect.h = 31;
    m->p.dstRect.x = m->p.dstRect.y = 0;
    m->p.dstRect.w = m->p.dstRect.h = 31;
    m->p.step = 16;
    m->p.move = LEFT;
}

static void init_map_ghost(SDL_Renderer *r, GameMap *m) {

}

void draw_map_player(SDL_Renderer *r, GameMap *m) {


}

void init_map(SDL_Renderer *r, GameMap *m) {

    FILE *f = NULL;
    char line[40];
    size_t size = 33;
    unsigned int l = 0;
    SDL_Surface *s = NULL;
    unsigned short int count;

    m->ghost_pos_count = 0;
    if(!(f = fopen("mapmodel.txt", "r")))
        exit(-1);

    char *tmp;
    while(fgets(line, size, f)) {
        tmp = rindex(line, '\n');
        if(!tmp) *tmp = '\0';
        m->t_map[l] = (char*) malloc(sizeof(char) * 62);
        // printf("%s", line);
        if(!strchr(line, ';'))
            strcpy(m->t_map[l++], line);
    }
    if(l)
        m->sz = l;

    for (count = 0; count < l; count ++)
         printf("%s", m->t_map[count]);

    // free(line);
    fclose(f);

    s = SDL_LoadBMP("wall_h.bmp");
    if(s == NULL)
        exit(-1);
    m->wall = SDL_CreateTextureFromSurface(r, s);
    SDL_FreeSurface(s);
    s = SDL_LoadBMP("wall_x.bmp");
    if(s == NULL)
        exit(-1);
    m->cross = SDL_CreateTextureFromSurface(r, s);
    s = SDL_LoadBMP("ghost.bmp");
    if(s == NULL)
        exit(-1);
    m->ghost = SDL_CreateTextureFromSurface(r, s);
    SDL_FreeSurface(s);
    s = SDL_LoadBMP("special.bmp");
    if(s == NULL)
        exit(-1);
    m->special = SDL_CreateTextureFromSurface(r, s);
    s = SDL_LoadBMP("pils1.bmp");
    if(s == NULL)
        exit(-1);
    m->pils = SDL_CreateTextureFromSurface(r, s);
    s = SDL_LoadBMP("pacman.bmp");
    if(s == NULL)
        exit(-1);
    m->pacman = SDL_CreateTextureFromSurface(r, s);

    SDL_FreeSurface(s);

    init_map_player(r, m);
    for(count = 0; m->ghost_pos_count; count++)
        init_map_ghost(r, m);
}

void move_player(GameMap *m) {

}

void move_ghost(GameMap *m) {

}

void update_map(GameMap *m) {


}

void send_event(GameMap *m) {

}


