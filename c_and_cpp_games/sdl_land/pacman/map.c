#include <stdio.h>
#include <stdlib.h>
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

    if(!(f = fopen("mapmodel.txt", "r"))) {
        exit(-1);
    }

    while(getline(&line, &size, f) != -1) {
        // m->
        printf("%s\n", line);
    }

    free(line);
    fclose(f);
}


