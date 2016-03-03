#ifndef PACMAN_H
#define PACMAN_H

enum move { NONE, UP, DOWN, LEFT, RIGHT};

typedef struct Pacman {
    SDL_Rect rect;
    enum move move;
    unsigned short step;
} Pacman;

Pacman *create_pacman();
void delete_snake(Pacman *s);
void init_snake(SDL_Renderer *r, Pacman *);


#endif


