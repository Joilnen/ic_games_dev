#include <SDL2/SDL.h>
#include "draw.h"
#include "ghost.h"

void draw_pacman(SDL_Renderer *r, Pacman *s) {

    SDL_SetRenderDrawColor(r, 255, 255, 255, 255);
    SDL_RenderFillRect(r, &s->rect);
}

void draw_ghost(SDL_Renderer *r, Ghost *s) {
    SDL_SetRenderDrawColor(r, 255, 255, 0, 255);
    SDL_RenderFillRect(r, &s->rect);
    SDL_RenderCopy(r, s->sprite, &s->srcRect, &s->dstRect);
    SDL_RenderPresent(r);
}

