#include <SDL2/SDL.h>
#include "pacman.h"
#include "map.h"
#include "event.h"

static unsigned short check_colide_player(GameMap *m, enum move to) {

    if (to == UP && m->pacman_pos.y < 1)
        m->pacman_pos.y = MAP_HEIGHT - 2;
    else if (to == DOWN && m->pacman_pos.y > MAP_HEIGHT - 2)
        m->pacman_pos.y = 1;
    else if (to == LEFT && m->pacman_pos.x < 1)
        m->pacman_pos.x = MAP_WIDTH -1;
    else if(to == RIGHT && m->pacman_pos.x > MAP_WIDTH - 1)
         m->pacman_pos.x = 1;

    if (to == LEFT && m->t_map[m->pacman_pos.y][m->pacman_pos.x - 1] == 'o' ||
       to == RIGHT && m->t_map[m->pacman_pos.y][m->pacman_pos.x + 1] == 'o' ||
       to == UP && m->t_map[m->pacman_pos.y - 1][m->pacman_pos.x] == 'o' ||
       to == DOWN && m->t_map[m->pacman_pos.y + 1][m->pacman_pos.x] == 'o' ||

       to == LEFT && m->t_map[m->pacman_pos.y][m->pacman_pos.x - 1] == '#' ||
       to == RIGHT && m->t_map[m->pacman_pos.y][m->pacman_pos.x + 1] == '#' ||
       to == UP && m->t_map[m->pacman_pos.y - 1][m->pacman_pos.x] == '#' ||
       to == DOWN && m->t_map[m->pacman_pos.y + 1][m->pacman_pos.x] == '#' ||

       to == LEFT && m->t_map[m->pacman_pos.y][m->pacman_pos.x - 1] == 'I' ||
       to == RIGHT && m->t_map[m->pacman_pos.y][m->pacman_pos.x + 1] == 'I' ||
       to == UP && m->t_map[m->pacman_pos.y - 1][m->pacman_pos.x] == 'I' ||
       to == DOWN && m->t_map[m->pacman_pos.y + 1][m->pacman_pos.x] == 'I')
            return 1;

    return 0;
}

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
                s->p.move = UP;
            if(e.key.keysym.sym == SDLK_DOWN)
                s->p.move = DOWN;
            if(e.key.keysym.sym == SDLK_LEFT)
                s->p.move = LEFT;
            if(e.key.keysym.sym == SDLK_RIGHT)
                s->p.move = RIGHT;
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
                m->p.p.move = UP;
            if(e.key.keysym.sym == SDLK_DOWN && !check_colide_player(m, DOWN))
                m->p.p.move = DOWN;
            if(e.key.keysym.sym == SDLK_LEFT && !check_colide_player(m, LEFT))
                m->p.p.move = LEFT;
            if(e.key.keysym.sym == SDLK_RIGHT && !check_colide_player(m, RIGHT))
                m->p.p.move = RIGHT;
        }
    }
}


