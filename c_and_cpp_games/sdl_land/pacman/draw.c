#include <SDL2/SDL.h>
#include "draw.h"
#include "ghost.h"
#include "map.h"

static void draw_pacman(SDL_Renderer *r, GameMap *m) {

    m->p.srcRect.y = 0;
    m->p.srcRect.w = m->p.srcRect.h = 32;
    /* m->p.srcRect.x = (m->p.srcRect.x)? 0: 32; this is in update because timer lapse */
    m->p.dstRect.x = m->pacman_pos.x * 32; m->p.dstRect.y = m->pacman_pos.y * 32;
    m->p.dstRect.w = m->p.dstRect.h = 32;

    if(m->p.move == LEFT || m->p.move == NONE)
        SDL_RenderCopy(r, m->p.sprite, &m->p.srcRect, &m->p.dstRect);
    else if(m->p.move == RIGHT)
        SDL_RenderCopyEx(r, m->p.sprite, &m->p.srcRect, &m->p.dstRect, 0, NULL, SDL_FLIP_HORIZONTAL);
    else if(m->p.move == UP)
        SDL_RenderCopyEx(r, m->p.sprite, &m->p.srcRect, &m->p.dstRect, 90, NULL, SDL_FLIP_NONE);
    else if(m->p.move == DOWN)
        SDL_RenderCopyEx(r, m->p.sprite, &m->p.srcRect, &m->p.dstRect, -90, NULL, SDL_FLIP_NONE);
}

static void draw_ghost(SDL_Renderer *r, Ghost *s) {
    // SDL_SetRenderDrawColor(r, 255, 255, 0, 255);
    // SDL_RenderFillRect(r, &s->rect);
}

void draw_map(SDL_Renderer *r, GameMap *m) {

    unsigned int x = 0, y = 0;
    unsigned int c_count = 0, l_count = 0;
    char *t = NULL;

    for(c_count = 0; c_count < m->sz; c_count++) {
        t = m->t_map[c_count];
        for(l_count = 0; l_count < 31; l_count++) {
            // printf("Letra %c[%d %d]", *t, l_count, c_count);
            // printf(".%c", *t, l_count, c_count);
            SDL_Rect srect, drect;
            srect.x = srect.y = 0;
            srect.w = srect.h = 32;
            drect.x = l_count * 32; drect.y = c_count * 32;
            drect.w = drect.h = 32;

            if(*t == 'o')
                SDL_RenderCopy(r, m->wall, &srect, &drect);
            else if(*t == 'I')
                SDL_RenderCopyEx(r, m->wall, &srect, &drect, 90, NULL, SDL_FLIP_NONE);
            else if(*t == '#')
                SDL_RenderCopy(r, m->cross, &srect, &drect);
            else if(*t == '.')
                SDL_RenderCopy(r, m->pils, &srect, &drect);
            else if(*t == '*')
                SDL_RenderCopy(r, m->big_pils, &srect, &drect);
            else if(*t == 'G') {
                // SDL_RenderCopy(r, m->ghost, &srect, &drect);
                m->ghost_born_pos.x = l_count;
                m->ghost_born_pos.y = c_count;
            }
            else if(*t == 'Y')
                SDL_RenderCopy(r, m->special, &srect, &drect);
            else if(*t == 'P') {
                // SDL_RenderCopy(r, m->pacman, &srect, &drect);
                draw_pacman(r, m);
                m->pacman_pos.x = l_count; m->pacman_pos.y = c_count;
            }
            else if(*t == '\n')
                break;
            t++;
        }
        // printf("\n");
    }
}

void draw_present(SDL_Renderer *r) {
    SDL_RenderPresent(r);
}


