#ifndef GOST_H
#define GOST_H

typedef struct Gost {
    int x, y;
    SDL_Rect rect;
} Gost;

Gost *create_gost();
void delete_gost(Gost *s);
void init_gost(SDL_Renderer *r, Gost *);


#endif
