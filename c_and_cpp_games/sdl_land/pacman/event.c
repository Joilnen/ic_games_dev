#include <SDL2/SDL.h>
#include "pacman.h"
#include "event.h"

static void game_exit() {
    SDL_Quit();
}

void get_event(Pacman *s, unsigned int *r) {

    SDL_Event e;
    const Uint8* keyState = SDL_GetKeyboardState(NULL);

    if(SDL_PollEvent(&e)) {
        if(e.type == SDL_QUIT)
            *r = 0;

        if(e.type == SDL_KEYDOWN) {
            if(e.key.keysym.sym == SDLK_ESCAPE)
                *r = 0;
            if(e.key.keysym.sym == SDLK_UP)
                s->move = UP;
            if(e.key.keysym.sym == SDLK_DOWN)
                s->move = DOWN;
            if(e.key.keysym.sym == SDLK_LEFT)
                s->move = LEFT;
            if(e.key.keysym.sym == SDLK_RIGHT)
                s->move = RIGHT;
        }
        else if(e.type == SDL_KEYUP)
            s->move = NONE;
    }
}


