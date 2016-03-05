#include "update.h"
#include "defs.h"

void update(SDL_Renderer *r, Pacman *p, Ghost *g) {

    if(p->move == UP) {
        // p->rect.y -= p->step;
        g->dstRect.y -= g->step;
    }
    if(p->move == DOWN) {
        // p->rect.y += p->step;
        g->dstRect.y += g->step;
    }
    if(p->move == LEFT) {
        // p->rect.x -= p->step;
        g->dstRect.x -= g->step;
    }
    if(p->move == RIGHT) {
        // p->rect.x += p->step;
        g->dstRect.x += g->step;
    }

    if(p->rect.y < 0) p->rect.y = HEIGHT - 16;
    if(p->rect.y > HEIGHT - 16 ) p->rect.y = 0;
    if(p->rect.x < 0) p->rect.x = WIDTH - 16;
    if(p->rect.x > WIDTH - 16) p->rect.x = 0;

    if(g->dstRect.y < 0) g->dstRect.y = HEIGHT - 32;
    if(g->dstRect.y > HEIGHT - 32 ) g->dstRect.y = 0;
    if(g->dstRect.x < 0) g->dstRect.x = WIDTH - 32;
    if(g->dstRect.x > WIDTH - 32) g->dstRect.x = 0;

    if(p->move != NONE) {
        if(g->srcRect.x == 0)
            g->srcRect.x = 32;
        else
            g->srcRect.x = 0;
    }
    else
        g->srcRect.x = 0;

}

