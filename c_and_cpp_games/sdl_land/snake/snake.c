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

void init_body(SDL_Renderer *r, Snake *s) {
    s->rect.x = s->x = 200;
    s->rect.y = s->y = 200;
    s->rect.w = 16;
    s->rect.h = 16;
}



void draw_snake(SDL_Renderer *r, Snake *s) {
    SDL_SetRenderDrawColor(r, 255, 255, 255, 255);
    SDL_RenderFillRect(r, &s->rect);
}


