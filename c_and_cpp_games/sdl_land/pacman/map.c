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

void init_map(GameMap *m) {

    FILE *f = NULL;
    char *line;
    size_t size = 0;
    unsigned int l = 0, count;

    if(!(f = fopen("mapmodel.txt", "r"))) {
        exit(-1);
    }

    while(getline(&line, &size, f) != -1) {
        m->t_map[l] = (char*) malloc(sizeof(char) * 62);
        printf("%s", line);
        if(!strchr(line, ';'))
            strcpy(m->t_map[l++], line);
    }
    if(l)
        m->sz = l;

    for (count = 0; count < l; count ++)
        printf("%s", m->t_map[count]);

    free(line);
    fclose(f);
}



