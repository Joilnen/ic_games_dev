#include "update.h"
#include "timer.h"

void update(SDL_Renderer *r, Pacman *p) {

    Uint32 d = get_elapsed_time();
    // printf("%d\n", d);
    float delta = d * 0.0001;
    printf("%f\n", p->step * delta);

    if(p->move == UP) {
        p->rect.y -= (p->step * delta);
    }
    if(p->move == DOWN) {
        p->rect.y += (1 + p->step * delta);
    }
    if(p->move == LEFT) {
        p->rect.x -= (p->step * delta);
    }
    if(p->move == RIGHT) {
        p->rect.x += (1 + p->step * delta);
    }
    printf("X %d  Y %d\n", p->rect.x, p->rect.y);

    if(p->rect.y < 0) p->rect.y = 480;
    if(p->rect.y > 480) p->rect.y = 0;
    if(p->rect.x < 0) p->rect.x = 480;
    if(p->rect.x > 480) p->rect.x = 0;
}
