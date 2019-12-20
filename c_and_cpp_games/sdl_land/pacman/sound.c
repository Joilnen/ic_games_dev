#include "map.h"
#include "sound.h"

static int _init(GameMap *g) {
    g->sound = (struct Sound *) malloc(sizeof (struct Sound));

    if(Mix_Init(MIX_INIT_MOD) & MIX_INIT_MOD)
        printf("Mix inicializado legal %d decoders\n", Mix_GetNumMusicDecoders());
    else
        printf("Mix nao inicializado %s\n", Mix_GetError());

    if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024))
        printf("Error opening audio device\n");
    Mix_AllocateChannels(2);
    g->sound->music = Mix_LoadMUS("sounds/pop_refrao.xm");
    if(g->sound->music) {
        // Mix_PlayMusic(g->sound->music, -1);
    }
    else {
        printf("Mix musica nao carregou %s\n", Mix_GetError());
    }

    Mix_Resume(-1);
    Mix_Volume(-1, MIX_MAX_VOLUME);
    printf("%d channels playing\n", Mix_Playing(-1));

}

int init_sound(GameMap *g) {
     _init(g);

     return 0;
}

