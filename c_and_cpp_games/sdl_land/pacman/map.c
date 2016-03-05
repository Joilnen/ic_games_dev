#include <stdio.h>
#include <stdlib.h>
#include "map.h"

GameMap *create_map() {
    GameMap *m = (GameMap*) malloc(sizeof(GameMap));
    if(!m)
        return NULL;
    return m;
}

void init_map(GameMap *m) {
    FILE *f = NULL;

    if(!(f = fopen("mapmodel.txt", "r"))) {
        exit(-1);
    }

    fclose(f);
}


