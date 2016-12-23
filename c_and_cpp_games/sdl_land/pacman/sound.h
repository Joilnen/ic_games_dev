#ifndef SOUND_H
#define SOUND_H

#include <SDL2/SDL_mixer.h>
#include "map.h"

struct Sound {
    Mix_Music *music;

};

int init_sound(GameMap *);

#endif

