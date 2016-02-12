#include <SDL2/SDL.h>
#include "draw.h"

void draw_snake(SDL_Renderer *r, Snake *s) {
    SDL_SetRenderDrawColor(r, 255, 255, 255, 255);
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

    SDL_RenderFillRect(r, &s->rect);
}

