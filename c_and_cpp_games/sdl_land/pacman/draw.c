#include <SDL2/SDL.h>
#include "draw.h"
#include "ghost.h"
#include "map.h"

void draw_pacman(SDL_Renderer *r, Pacman *s) {
    SDL_SetRenderDrawColor(r, 255, 255, 0, 255);
    SDL_RenderFillRect(r, &s->rect);
    if(s->move == LEFT || s->move == NONE)
        SDL_RenderCopy(r, s->sprite, &s->srcRect, &s->dstRect);
    else if(s->move == RIGHT)
        SDL_RenderCopyEx(r, s->sprite, &s->srcRect, &s->dstRect, 0, NULL, SDL_FLIP_HORIZONTAL);
    else if(s->move == UP)
        SDL_RenderCopyEx(r, s->sprite, &s->srcRect, &s->dstRect, 90, NULL, SDL_FLIP_NONE);
    else if(s->move == DOWN)
        SDL_RenderCopyEx(r, s->sprite, &s->srcRect, &s->dstRect, -90, NULL, SDL_FLIP_NONE);
}

void draw_ghost(SDL_Renderer *r, Ghost *s) {
    SDL_SetRenderDrawColor(r, 255, 255, 0, 255);
    SDL_RenderFillRect(r, &s->rect);
}

void draw_map(SDL_Renderer *r, GameMap *m) {
    unsigned int x = 0, y = 0;
    unsigned int c_count = 0, l_count = 0;
    char *t = NULL;

    for(c_count = 0; c_count < m->sz; c_count++) {
        t = m->t_map[c_count];
        for(l_count = 0; l_count < 62; l_count++) {
            printf("Letra %c %d %d\n", *t, l_count, c_count);
            if(*t == 'o') {
                SDL_Rect rect;
                rect.x = l_count * 16; rect.y = c_count * 16;
                rect.w = rect.h = 16;
                SDL_RenderCopy(r, m->wall, &rect, NULL);
            }
            t++;
        }
    }
}

void draw_present(SDL_Renderer *r) {
    SDL_RenderPresent(r);
}
