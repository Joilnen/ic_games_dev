#include <SDL2/SDL.h>
#include "draw.h"

void draw_snake(SDL_Renderer *r, Snake *s) {

    if(s->move == UP) {
        s->rect.y -= s->step;
    }
    if(s->move == DOWN) {
        s->rect.y += s->step;
    }
    if(s->move == LEFT) {
        s->rect.x -= s->step;
    }
    if(s->move == RIGHT) {
        s->rect.x += s->step;
    }

    if(s->rect.y < 0) s->rect.y = 480;
    if(s->rect.y > 480) s->rect.y = 0;
    if(s->rect.x < 0) s->rect.x = 480;
    if(s->rect.x > 480) s->rect.x = 0;

    SDL_SetRenderDrawColor(r, 255, 255, 255, 255);
    SDL_RenderFillRect(r, &s->rect);
}


