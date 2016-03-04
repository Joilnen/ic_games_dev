#include <SDL2/SDL.h>

static Uint32 lasttime = 0;

Uint32 get_elapsed_time() {
    Uint32 d = SDL_GetTicks() - lasttime;
    lasttime = SDL_GetTicks();

    return d;
}
