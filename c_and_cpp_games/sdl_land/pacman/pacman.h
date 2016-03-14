#ifndef PACMAN_H
#define PACMAN_H

enum move { NONE, UP, DOWN, LEFT, RIGHT};

typedef struct Pacman {
    SDL_Rect rect;
    enum move move;
    SDL_Rect srcRect, dstRect;
    SDL_Texture *sprite;
    unsigned short step;
    unsigned short l_count, c_count;
} Pacman;

Pacman *create_pacman();
void delete_snake(Pacman *s);
void init_snake(SDL_Renderer *r, Pacman *);
void init_pacman(SDL_Renderer *r, Pacman *s);

#endif


