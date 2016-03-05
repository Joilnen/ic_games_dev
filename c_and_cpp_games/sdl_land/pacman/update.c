#include "update.h"
#include "defs.h"

void update(SDL_Renderer *r, Pacman *p, Ghost *g) {

    if(p->move == UP) {
        // p->rect.y -= p->step;
        p->dstRect.y -= p->step;
    }
    if(p->move == DOWN) {
        // p->rect.y += p->step;
        p->dstRect.y += p->step;
    }
    if(p->move == LEFT) {
        // p->rect.x -= p->step;
        p->dstRect.x -= p->step;
    }
    if(p->move == RIGHT) {
        // p->rect.x += p->step;
        p->dstRect.x += p->step;
    }

    if(p->dstRect.y < 0) p->dstRect.y = HEIGHT - 32;
    if(p->dstRect.y > HEIGHT - 32 ) p->dstRect.y = 0;
    if(p->dstRect.x < 0) p->dstRect.x = WIDTH - 32;
    if(p->dstRect.x > WIDTH - 32) p->dstRect.x = 0;

    if(p->move != NONE) {
        if(p->srcRect.x == 0)
            p->srcRect.x = 32;
        else
            p->srcRect.x = 0;
    }
    else
        p->srcRect.x = 0;
}

