#ifndef SNAKE_H
#define SNAKE_H

typedef struct Snake {
    int x, y;
    SDL_Rect rect;
} Snake;

Snake *create_snake();
void delete_snake(Snake *s);
void init_snake(SDL_Renderer *r, Snake *);


#endif
