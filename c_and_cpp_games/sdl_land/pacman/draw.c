#include <SDL2/SDL.h>
#include "draw.h"
#include "ghost.h"
#include "map.h"

static void draw_pacman(SDL_Renderer *r, GameMap *m) {

    m->p.p.srcRect.y = 0;
    m->p.p.srcRect.w = m->p.p.srcRect.h = 32;
    /* m->p.p.srcRect.x = (m->p.p.srcRect.x)? 0: 32; this is in update because timer lapse */
    m->p.p.dstRect.x = m->pacman_pos.x * 32; m->p.p.dstRect.y = m->pacman_pos.y * 32;
    m->p.p.dstRect.w = m->p.p.dstRect.h = 32;

    if(m->p.p.move == LEFT || m->p.p.move == NONE)
        SDL_RenderCopy(r, m->p.p.sprite, &m->p.p.srcRect, &m->p.p.dstRect);
    else if(m->p.p.move == RIGHT)
        SDL_RenderCopyEx(r, m->p.p.sprite, &m->p.p.srcRect, &m->p.p.dstRect, 0, NULL, SDL_FLIP_HORIZONTAL);
    else if(m->p.p.move == UP)
        SDL_RenderCopyEx(r, m->p.p.sprite, &m->p.p.srcRect, &m->p.p.dstRect, 90, NULL, SDL_FLIP_NONE);
    else if(m->p.p.move == DOWN)
        SDL_RenderCopyEx(r, m->p.p.sprite, &m->p.p.srcRect, &m->p.p.dstRect, -90, NULL, SDL_FLIP_NONE);
}

static void draw_ghost(SDL_Renderer *r, GameMap *m) {
    m->g[0].p.srcRect.y = 0;
    m->g[0].p.srcRect.w = m->g[0].p.srcRect.h = 32;
    /* m->p.p.srcRect.x = (m->p.p.srcRect.x)? 0: 32; this is in update because timer lapse */
    m->g[0].p.dstRect.x = m->g[0].p.x * 32; m->g[0].p.dstRect.y = m->g[0].p.y * 32;
    m->g[0].p.dstRect.w = m->g[0].p.dstRect.h = 32;

    SDL_RenderCopy(r, m->g[0].p.sprite, &m->g[0].p.srcRect, &m->g[0].p.dstRect);
    /****
    if(m->p.p.move == LEFT || m->p.p.move == NONE)
        SDL_RenderCopy(r, m->p.p.sprite, &m->p.p.srcRect, &m->p.p.dstRect);
    else if(m->p.p.move == RIGHT)
        SDL_RenderCopyEx(r, m->p.p.sprite, &m->p.p.srcRect, &m->p.p.dstRect, 0, NULL, SDL_FLIP_HORIZONTAL);
    else if(m->p.p.move == UP)
        SDL_RenderCopyEx(r, m->p.p.sprite, &m->p.p.srcRect, &m->p.p.dstRect, 90, NULL, SDL_FLIP_NONE);
    else if(m->p.p.move == DOWN)
        SDL_RenderCopyEx(r, m->p.p.sprite, &m->p.p.srcRect, &m->p.p.dstRect, -90, NULL, SDL_FLIP_NONE);
    ****/
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
                m->g[0].p.x = l_count;
                m->g[0].p.y = c_count;
                draw_ghost(r, m);
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


