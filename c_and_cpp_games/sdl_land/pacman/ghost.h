#ifndef GOST_H
#define GOST_H

typedef struct Ghost {
    int x, y;
    SDL_Rect rect;
    SDL_Rect srcRect, dstRect;
    SDL_Texture *sprite;
    unsigned int step;
    unsigned short l_count, c_count;
} Ghost;

Ghost *create_ghost();
void delete_ghost(Ghost *s);
void init_ghost(SDL_Renderer *r, Ghost *);

#endif
