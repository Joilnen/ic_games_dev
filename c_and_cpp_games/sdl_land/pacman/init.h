#ifndef INIT_H
#define INIT_H

#include <SDL2/SDL.h>
#include "defs.h"

enum GameState {
    QUIT, MENU, PREPLAYING, PLAYING, CAN_EAT_GHOST, WIN, LOST, RESET, CREDITS
};

typedef struct GameScreen {
    SDL_Window *window;
    SDL_Renderer *renderer;
    enum GameState state;
} GameScreen;

void gamescreen_init(GameScreen *g);

#endif


