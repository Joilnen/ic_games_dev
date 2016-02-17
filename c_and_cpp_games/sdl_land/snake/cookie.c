#include <SDL2/SDL.h>
#include "cookie.h"


Cookie *create_cookie() {

    Cookie *s = (Cookie*) malloc(sizeof(Cookie));
    if(s)
        return s;

    return NULL;
}

void init_cookie(SDL_Renderer *r, Cookie *s) {
    s->rect.x = 300;
    s->rect.y = 200;
    s->rect.w = 16;
    s->rect.h = 16;
}

void draw_cookie(SDL_Renderer *r, Cookie *s) {
    SDL_SetRenderDrawColor(r, 255, 255, 0, 255);
    SDL_RenderFillRect(r, &s->rect);
}


