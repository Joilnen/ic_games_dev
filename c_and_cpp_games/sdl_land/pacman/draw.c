#include <SDL2/SDL.h>
#include "draw.h"
#include "timer.h"

void draw_pacman(SDL_Renderer *r, Pacman *s) {
    Uint32 d = get_elapsed_time();
    // printf("%d\n", d);
    float delta = d * 0.007;
    printf("%f\n", delta);

    if(s->move == UP) {
        s->rect.y -= (s->step * delta);
    }
    if(s->move == DOWN) {
        s->rect.y += (s->step * delta);
    }
    if(s->move == LEFT) {
        s->rect.x -= (s->step * delta);
    }
    if(s->move == RIGHT) {
        s->rect.x += (s->step * delta);
    }

    if(s->rect.y < 0) s->rect.y = 480;
    if(s->rect.y > 480) s->rect.y = 0;
    if(s->rect.x < 0) s->rect.x = 480;
    if(s->rect.x > 480) s->rect.x = 0;

    SDL_SetRenderDrawColor(r, 255, 255, 255, 255);
    SDL_RenderFillRect(r, &s->rect);
}


