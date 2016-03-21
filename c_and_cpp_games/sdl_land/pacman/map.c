#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pacman.h"
#include "map.h"

GameMap *create_map() {
    GameMap *m = (GameMap*) malloc(sizeof(GameMap));
    if(!m)
        return NULL;
    return m;
}

static void init_map_player(SDL_Renderer *r, GameMap *m) {
    SDL_Surface *t = SDL_LoadBMP("pacman.bmp");
    m->p.sprite = SDL_CreateTextureFromSurface(r, t);
    SDL_FreeSurface(t);
    m->p.srcRect.x = m->p.srcRect.y = 0;
    m->p.srcRect.x = 32;
    m->p.srcRect.w = m->p.srcRect.h = 31;
    m->p.dstRect.x = m->p.dstRect.y = 0;
    m->p.dstRect.w = m->p.dstRect.h = 31;
    m->p.step = 16;
    m->p.move = NONE;
}

static void init_map_ghost(SDL_Renderer *r, GameMap *m) {
    SDL_Surface *t = SDL_LoadBMP("ghost.bmp");
    int i;
    for(i = 0; i < m->ghost_counter; i++) {
        m->g[i].sprite = SDL_CreateTextureFromSurface(r, t);
        m->g[i].srcRect.x = m->ghost_born_pos.x * 32;
        m->g[i].srcRect.y = m->ghost_born_pos.y * 32;
        m->g[i].srcRect.w = m->g[i].srcRect.h = 31;
    }
    SDL_FreeSurface(t);
}

void draw_map_player(SDL_Renderer *r, GameMap *m) {


}

void init_map(SDL_Renderer *r, GameMap *m, GameScreen *screen) {

    FILE *f = NULL;
    char line[MAX_MAP_LINE_SZ];
    unsigned int l = 0;
    SDL_Surface *s = NULL;
    unsigned short int count;
    char *tmp = NULL;

    m->ghost_pos_count = 0;
    if(!(f = fopen("mapmodel.txt", "r")))
        exit(-1);

    while(fgets(line, MAX_MAP_LINE_SZ, f)) {
        m->t_map[l] = (char*) malloc(sizeof(char) * MAX_MAP_LINE_SZ);
        printf("%s\n", line);
        if(!strchr(line, ';') && !strchr(line, '=')) {
            if(tmp = index(line, '\n'))
                *tmp = '\0';
            strcpy(m->t_map[l++], line);
        }
        else if(strchr(line, '=')) {
            char tmp[MAX_GHOST_COUNTER_SZ];
            unsigned short s;

            if(strlen(line) - 1 > MAX_GHOST_COUNTER_SZ)
                exit(-1);
            strcpy(tmp, line + 1);
            m->ghost_counter = atoi(tmp);
        }
    }

    fclose(f);

    if(l)
        m->sz = l;

    for (count = 0; count < l; count ++)
         printf("%s\n", m->t_map[count]);

    s = SDL_LoadBMP("wall_h.bmp");
    if(s == NULL)
        exit(-1);
    m->wall = SDL_CreateTextureFromSurface(r, s);
    SDL_FreeSurface(s);
    s = SDL_LoadBMP("wall_x.bmp");
    if(s == NULL)
        exit(-1);
    m->cross = SDL_CreateTextureFromSurface(r, s);
    s = SDL_LoadBMP("ghost.bmp");
    if(s == NULL)
        exit(-1);
    m->ghost = SDL_CreateTextureFromSurface(r, s);
    SDL_FreeSurface(s);
    s = SDL_LoadBMP("special.bmp");
    if(s == NULL)
        exit(-1);
    m->special = SDL_CreateTextureFromSurface(r, s);
    s = SDL_LoadBMP("pils1.bmp");
    if(s == NULL)
        exit(-1);
    m->pils = SDL_CreateTextureFromSurface(r, s);
    s = SDL_LoadBMP("pils.bmp");
    if(s == NULL)
        exit(-1);
    m->big_pils = SDL_CreateTextureFromSurface(r, s);

    s = SDL_LoadBMP("pacman.bmp");
    if(s == NULL)
        exit(-1);
    m->pacman = SDL_CreateTextureFromSurface(r, s);

    SDL_FreeSurface(s);

    init_map_player(r, m);
    for(count = 0; m->ghost_pos_count; count++)
        init_map_ghost(r, m);
    m->score_counter = 0;
}

static void move_player(GameMap *m) {
    // printf("Cheguei %s\n", __FUNCTION__);
    unsigned short to = m->p.move;

    if(to == LEFT) {
        printf("%c\n", m->t_map[m->pacman_pos.y][m->pacman_pos.x - 1]);

        if(m->t_map[m->pacman_pos.y][m->pacman_pos.x - 1]  == ' ') {
           m->t_map[m->pacman_pos.y][m->pacman_pos.x - 1] = m->t_map[m->pacman_pos.y][m->pacman_pos.x];
           m->t_map[m->pacman_pos.y][m->pacman_pos.x] = ' ';
           m->pacman_pos.x--;
        }
        else if(m->t_map[m->pacman_pos.y][m->pacman_pos.x - 1]  == '.') {
           m->t_map[m->pacman_pos.y][m->pacman_pos.x - 1] = m->t_map[m->pacman_pos.y][m->pacman_pos.x];
           m->t_map[m->pacman_pos.y][m->pacman_pos.x] = ' ';
           m->score_counter++;
           m->pacman_pos.x--;
           printf("Ate pils\n");
        }
        else if(m->t_map[m->pacman_pos.y][m->pacman_pos.x - 1]  == '*') {
           m->t_map[m->pacman_pos.y][m->pacman_pos.x - 1] = m->t_map[m->pacman_pos.y][m->pacman_pos.x];
           m->t_map[m->pacman_pos.y][m->pacman_pos.x] = ' ';
           m->score_counter += 10;
           m->pacman_pos.x--;
           printf("Ate big pils can eat ghosts\n");
        }
        else if(m->t_map[m->pacman_pos.y][m->pacman_pos.x - 1]  == 'Y') {
           m->t_map[m->pacman_pos.y][m->pacman_pos.x - 1] = m->t_map[m->pacman_pos.y][m->pacman_pos.x];
           m->t_map[m->pacman_pos.y][m->pacman_pos.x] = ' ';
           m->score_counter += 30;
           m->pacman_pos.x--;
           printf("Ate fruit\n");
        }
        else if(m->t_map[m->pacman_pos.y][m->pacman_pos.x - 1]  == 'G') {
           m->t_map[m->pacman_pos.y][m->pacman_pos.x - 1] = m->t_map[m->pacman_pos.y][m->pacman_pos.x];
           m->t_map[m->pacman_pos.y][m->pacman_pos.x] = ' ';
           m->score_counter += 30;
           m->pacman_pos.x--;
           printf("Ate ghost or die\n");
        }
    }
    else if(to == RIGHT) {

        printf("%c\n", m->t_map[m->pacman_pos.y][m->pacman_pos.x + 1]);

        if(m->t_map[m->pacman_pos.y][m->pacman_pos.x + 1]  == ' ') {
           m->t_map[m->pacman_pos.y][m->pacman_pos.x + 1] = m->t_map[m->pacman_pos.y][m->pacman_pos.x];
           m->t_map[m->pacman_pos.y][m->pacman_pos.x] = ' ';
           m->pacman_pos.x++;
        }
        else if(m->t_map[m->pacman_pos.y][m->pacman_pos.x + 1]  == '.') {
           m->t_map[m->pacman_pos.y][m->pacman_pos.x + 1] = m->t_map[m->pacman_pos.y][m->pacman_pos.x];
           m->t_map[m->pacman_pos.y][m->pacman_pos.x] = ' ';
           m->score_counter++;
           m->pacman_pos.x++;
           printf("Ate pils\n");
        }
        else if(m->t_map[m->pacman_pos.y][m->pacman_pos.x + 1]  == '*') {
           m->t_map[m->pacman_pos.y][m->pacman_pos.x + 1] = m->t_map[m->pacman_pos.y][m->pacman_pos.x];
           m->t_map[m->pacman_pos.y][m->pacman_pos.x] = ' ';
           m->score_counter += 10;
           m->pacman_pos.x++;
           printf("Ate big pils can eat ghosts\n");
        }
        else if(m->t_map[m->pacman_pos.y][m->pacman_pos.x + 1]  == 'Y') {
           m->t_map[m->pacman_pos.y][m->pacman_pos.x + 1] = m->t_map[m->pacman_pos.y][m->pacman_pos.x];
           m->t_map[m->pacman_pos.y][m->pacman_pos.x] = ' ';
           m->score_counter += 30;
           m->pacman_pos.x++;
           printf("Ate fruit\n");
        }
        else if(m->t_map[m->pacman_pos.y][m->pacman_pos.x + 1]  == 'G') {
           m->t_map[m->pacman_pos.y][m->pacman_pos.x + 1] = m->t_map[m->pacman_pos.y][m->pacman_pos.x];
           m->t_map[m->pacman_pos.y][m->pacman_pos.x] = ' ';
           m->score_counter += 30;
           m->pacman_pos.x++;
           printf("Ate ghost or die\n");
        }
    }
    else if(to == UP) {

        printf("%c\n", m->t_map[m->pacman_pos.y - 1][m->pacman_pos.x]);

        if(m->t_map[m->pacman_pos.y - 1][m->pacman_pos.x]  == ' ') {
           m->t_map[m->pacman_pos.y - 1][m->pacman_pos.x] = m->t_map[m->pacman_pos.y][m->pacman_pos.x];
           m->t_map[m->pacman_pos.y][m->pacman_pos.x] = ' ';
           m->pacman_pos.y--;
        }
        else if(m->t_map[m->pacman_pos.y - 1][m->pacman_pos.x]  == '.') {
           m->t_map[m->pacman_pos.y - 1][m->pacman_pos.x] = m->t_map[m->pacman_pos.y][m->pacman_pos.x];
           m->t_map[m->pacman_pos.y][m->pacman_pos.x] = ' ';
           m->score_counter++;
           m->pacman_pos.y--;

           printf("Ate pils\n");
        }
        else if(m->t_map[m->pacman_pos.y - 1][m->pacman_pos.x]  == '*') {
           m->t_map[m->pacman_pos.y - 1][m->pacman_pos.x] = m->t_map[m->pacman_pos.y][m->pacman_pos.x];
           m->t_map[m->pacman_pos.y][m->pacman_pos.x] = ' ';
           m->score_counter += 10;
           m->pacman_pos.y--;
           printf("Ate big pils can eat ghosts\n");
        }
        else if(m->t_map[m->pacman_pos.y - 1][m->pacman_pos.x]  == 'Y') {
           m->t_map[m->pacman_pos.y - 1][m->pacman_pos.x] = m->t_map[m->pacman_pos.y][m->pacman_pos.x];
           m->t_map[m->pacman_pos.y][m->pacman_pos.x] = ' ';
           m->score_counter += 30;
           m->pacman_pos.y--;
           printf("Ate fruit\n");
        }
        else if(m->t_map[m->pacman_pos.y - 1][m->pacman_pos.x]  == 'G') {
           m->t_map[m->pacman_pos.y - 1][m->pacman_pos.x] = m->t_map[m->pacman_pos.y][m->pacman_pos.x];
           m->t_map[m->pacman_pos.y][m->pacman_pos.x] = ' ';
           m->score_counter += 30;
           m->pacman_pos.y--;
           printf("Ate ghost or die\n");
        }
    }
    else if(to == DOWN) {

        printf("%c\n", m->t_map[m->pacman_pos.y + 1][m->pacman_pos.x]);

        if(m->t_map[m->pacman_pos.y + 1][m->pacman_pos.x]  == ' ') {
           m->t_map[m->pacman_pos.y + 1][m->pacman_pos.x] = m->t_map[m->pacman_pos.y][m->pacman_pos.x];
           m->t_map[m->pacman_pos.y][m->pacman_pos.x] = ' ';
           m->pacman_pos.y++;
        }
        else if(m->t_map[m->pacman_pos.y + 1][m->pacman_pos.x]  == '.') {
           m->t_map[m->pacman_pos.y + 1][m->pacman_pos.x] = m->t_map[m->pacman_pos.y][m->pacman_pos.x];
           m->t_map[m->pacman_pos.y][m->pacman_pos.x] = ' ';
           m->score_counter++;
           m->pacman_pos.y++;

           printf("Ate pils\n");
        }
        else if(m->t_map[m->pacman_pos.y + 1][m->pacman_pos.x]  == '*') {
           m->t_map[m->pacman_pos.y + 1][m->pacman_pos.x] = m->t_map[m->pacman_pos.y][m->pacman_pos.x];
           m->t_map[m->pacman_pos.y][m->pacman_pos.x] = ' ';
           m->score_counter += 10;
           m->pacman_pos.y++;
           printf("Ate big pils can eat ghosts\n");
        }
        else if(m->t_map[m->pacman_pos.y + 1][m->pacman_pos.x]  == 'Y') {
           m->t_map[m->pacman_pos.y + 1][m->pacman_pos.x] = m->t_map[m->pacman_pos.y][m->pacman_pos.x];
           m->t_map[m->pacman_pos.y][m->pacman_pos.x] = ' ';
           m->score_counter += 30;
           m->pacman_pos.y++;
           printf("Ate fruit\n");
        }
        else if(m->t_map[m->pacman_pos.y + 1][m->pacman_pos.x]  == 'G') {
           m->t_map[m->pacman_pos.y + 1][m->pacman_pos.x] = m->t_map[m->pacman_pos.y][m->pacman_pos.x];
           m->t_map[m->pacman_pos.y][m->pacman_pos.x] = ' ';
           m->score_counter += 30;
           m->pacman_pos.y++;
           printf("Ate ghost or die\n");
        }
    }
}

static void move_ghost(GameMap *m, unsigned short to) {

}

void update_map(GameMap *m) {
    move_player(m);
    if(m->p.move != NONE)
        m->p.srcRect.x = (m->p.srcRect.x)? 0: 32;

}

void send_event(GameMap *m) {

}

unsigned short check_colide_player(GameMap *m, enum move to) {

    if(to == LEFT && m->t_map[m->pacman_pos.y][m->pacman_pos.x - 1] == 'o' ||
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

