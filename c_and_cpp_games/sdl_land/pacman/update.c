#include "update.h"

void update(SDL_Renderer *r, Pacman *p) {

    if(p->move == UP)
        p->rect.y -= p->step;
    if(p->move == DOWN)
        p->rect.y += p->step;
    if(p->move == LEFT)
        p->rect.x -= p->step;
    if(p->move == RIGHT)
        p->rect.x += p->step;

    if(p->rect.y < 0) p->rect.y = 480;
    if(p->rect.y > 480) p->rect.y = 0;
    if(p->rect.x < 0) p->rect.x = 480;
    if(p->rect.x > 480) p->rect.x = 0;
}

