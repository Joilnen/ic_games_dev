#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"

GameMap *create_map() {

    GameMap *m = (GameMap*) malloc(sizeof(GameMap));
    if(!m)
        return NULL;
    return m;
}

void parsing_map() {

}

void init_map(SDL_Renderer *r, GameMap *m) {

    FILE *f = NULL;
    char *line;
    size_t size = 0;
    unsigned int l = 0, count;
    SDL_Surface *s = NULL;

    if(!(f = fopen("mapmodel.txt", "r"))) {
        exit(-1);
    }

    while(getline(&line, &size, f) != -1) {
        m->t_map[l] = (char*) malloc(sizeof(char) * 62);
        // printf("%s", line);
        if(!strchr(line, ';'))
            strcpy(m->t_map[l++], line);
    }
    if(l)
        m->sz = l;

    // for (count = 0; count < l; count ++)
    //     printf("%s", m->t_map[count]);

    free(line);
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
    SDL_FreeSurface(s);
}



