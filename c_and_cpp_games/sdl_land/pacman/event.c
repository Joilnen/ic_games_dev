#include <SDL2/SDL.h>
#include "pacman.h"
#include "map.h"
#include "event.h"

static void game_exit() {
    SDL_Quit();
}

void get_event_(Pacman *s, unsigned int *r) {

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
    }
}

void get_event(GameMap *m, unsigned int *r) {

    SDL_Event e;
    const Uint8* keyState = SDL_GetKeyboardState(NULL);

    if(SDL_PollEvent(&e)) {
        if(e.type == SDL_QUIT)
            *r = 0;

        if(e.type == SDL_KEYDOWN) {
            if(e.key.keysym.sym == SDLK_ESCAPE)
                *r = 0;
            if(e.key.keysym.sym == SDLK_UP && !check_colide_player(m, UP))
                m->p.move = UP;
            if(e.key.keysym.sym == SDLK_DOWN && !check_colide_player(m, DOWN))
                m->p.move = DOWN;
            if(e.key.keysym.sym == SDLK_LEFT && !check_colide_player(m, LEFT))
                m->p.move = LEFT;
            if(e.key.keysym.sym == SDLK_RIGHT && !check_colide_player(m, RIGHT))
                m->p.move = RIGHT;
        }
    }
}


