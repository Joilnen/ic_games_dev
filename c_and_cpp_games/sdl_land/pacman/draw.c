#include <SDL2/SDL.h>
#include "draw.h"

void draw_pacman(SDL_Renderer *r, Pacman *s) {

    SDL_SetRenderDrawColor(r, 255, 255, 255, 255);
    SDL_RenderFillRect(r, &s->rect);
}


