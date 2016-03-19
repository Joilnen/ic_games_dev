#ifndef UPDATE_H
#define UPDATE_H

#include <SDL2/SDL.h>
#include "pacman.h"
#include "ghost.h"
#include "map.h"

void update(SDL_Renderer*, GameMap *);
void update_(SDL_Renderer*, Pacman *, Ghost *);

#endif


