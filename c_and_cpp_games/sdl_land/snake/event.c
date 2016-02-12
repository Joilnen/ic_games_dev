#include <SDL2/SDL.h>
#include "snake.h"
#include "event.h"

static void game_exit() {
    SDL_Quit();
}

void get_event(Snake *s, unsigned int *r) {

    SDL_Event e;
    const Uint8* keyState = SDL_GetKeyboardState(NULL);

    if(SDL_PollEvent(&e)) {
        if(e.type == SDL_QUIT)
            *r = 0;

        if(e.type == SDL_KEYDOWN) {
            switch(e.key.keysym.sym) {
                case SDLK_ESCAPE:
                   *r = 0;
                break;
                case SDLK_UP:
                    s->move = UP;
                break;
                case SDLK_DOWN:
                    s->move = DOWN;
                break;
                case SDLK_LEFT:
                    s->move = LEFT;
                break;
                case SDLK_RIGHT:
                    s->move = RIGHT;
            }
        }
    }
}


