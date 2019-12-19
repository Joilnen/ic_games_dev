#ifndef SPRITE_H
#define SPRITE_H

enum move { NONE, UP, DOWN, LEFT, RIGHT};

typedef struct Sprite {
    int x, y;
    SDL_Rect rect;
    SDL_Rect srcRect, dstRect;
    SDL_Texture *sprite;
    unsigned int step;
    unsigned short l_count, c_count;
    enum move move;
} Sprite;

#endif


