#ifndef SNAKE_H
#define SNAKE_H

enum move { NONE, UP, DOWN, LEFT, RIGHT};

typedef struct Snake {
    SDL_Rect rect;
    enum move move;
    unsigned short step;
    unsigned short lenght;
} Snake;

Snake *create_snake();
void delete_snake(Snake *s);
void init_snake(SDL_Renderer *r, Snake *);


#endif
