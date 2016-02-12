#ifndef SNAKE_H
#define SNAKE_H

enum move { NONE, UP, DOWN, LEFT, RIGHT};

typedef struct Snake {
    int x, y;
    SDL_Rect rect;
    enum move move;
    unsigned short step;
} Snake;

Snake *create_snake();
void delete_snake(Snake *s);
void init_snake(SDL_Renderer *r, Snake *);


#endif
