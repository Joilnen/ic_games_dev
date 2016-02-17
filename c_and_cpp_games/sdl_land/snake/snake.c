#include <SDL2/SDL.h>
#include "snake.h"

Snake *create_snake() {

    Snake *s = (Snake*) malloc(sizeof(Snake));
    if(s)
        return s;

    return NULL;
}

void delete_snake(Snake *s) {

}

void init_snake(SDL_Renderer *r, Snake *s) {
    s->rect.x = 200;
    s->rect.y = 200;
    s->rect.w = 16;
    s->rect.h = 16;
    s->move = NONE;
    s->step = 16;
}


