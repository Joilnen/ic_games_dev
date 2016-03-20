#include "update.h"
#include "defs.h"
#include "map.h"

void update_(SDL_Renderer *r, Pacman *p, Ghost *g) {

    if(p->move == UP)
        p->dstRect.y -= p->step;
    if(p->move == DOWN)
        p->dstRect.y += p->step;
    if(p->move == LEFT)
        p->dstRect.x -= p->step;
    if(p->move == RIGHT)
        p->dstRect.x += p->step;

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
}

/** the first function in early stage of developping not used anymore **/
void update(SDL_Renderer *r, GameMap *m) {

    /****
    if(m->p.move == UP)
        m->p.dstRect.y -= m->p.step;
    if(m->p.move == DOWN)
        m->p.dstRect.y += m->p.step;
    if(m->p.move == LEFT)
        m->p.dstRect.x -= m->p.step;
    if(m->p.move == RIGHT)
        m->p.dstRect.x += m->p.step;

    if(m->p.dstRect.y < 0) m->p.dstRect.y = HEIGHT - 32;
    if(m->p.dstRect.y > HEIGHT - 32 ) m->p.dstRect.y = 0;
    if(m->p.dstRect.x < 0) m->p.dstRect.x = WIDTH - 32;
    if(m->p.dstRect.x > WIDTH - 32) m->p.dstRect.x = 0;

    if(m->p.move != NONE)
        m->p.srcRect.x = (m->p.srcRect.x)? 0: 32;
    ****/
}


