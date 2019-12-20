#include "update.h"
#include "defs.h"
#include "map.h"

static void inc_xpos(unsigned short *p) {
    if (*p == MAP_WIDTH)
        *p = 0;
    else
        ++*p;
}

static void dec_xpos(unsigned short *p) {
    if (*p == 0)
        *p = MAP_WIDTH - 1;
    else
        --*p;
}

static void inc_ypos(unsigned short *p) {
    ++*p;
    if (*p == MAP_HEIGHT - 1)
        *p = 0;
}

static void dec_ypos(unsigned short *p) {
    --*p;
    if (*p == 0)
        *p = MAP_HEIGHT - 1;
}

static void move_player(GameMap *m) {
    // printf("Cheguei %s\n", __FUNCTION__);
    unsigned short to = m->p.p.move;

    if (to == LEFT) {
        if (!m->pacman_pos.x) {
           m->t_map[m->pacman_pos.y][MAP_WIDTH - 1] = m->t_map[m->pacman_pos.y][m->pacman_pos.x];
           m->t_map[m->pacman_pos.y][m->pacman_pos.x] = ' ';
        }
        else if (m->pacman_pos.x && m->t_map[m->pacman_pos.y][m->pacman_pos.x - 1]  == ' ') {
           m->t_map[m->pacman_pos.y][m->pacman_pos.x - 1] = m->t_map[m->pacman_pos.y][m->pacman_pos.x];
           m->t_map[m->pacman_pos.y][m->pacman_pos.x] = ' ';
        }
        else if (m->pacman_pos.x && m->t_map[m->pacman_pos.y][m->pacman_pos.x - 1]  == '.') {
           m->t_map[m->pacman_pos.y][m->pacman_pos.x - 1] = m->t_map[m->pacman_pos.y][m->pacman_pos.x];
           m->t_map[m->pacman_pos.y][m->pacman_pos.x] = ' ';
           m->score_counter++;
           printf("Ate pils\n");
        }
        else if (m->pacman_pos.x && m->t_map[m->pacman_pos.y][m->pacman_pos.x - 1]  == '*') {
           m->t_map[m->pacman_pos.y][m->pacman_pos.x - 1] = m->t_map[m->pacman_pos.y][m->pacman_pos.x];
           m->t_map[m->pacman_pos.y][m->pacman_pos.x] = ' ';
           m->score_counter += 10;
           printf("Ate big pils can eat ghosts\n");
        }
        else if (m->pacman_pos.x && m->t_map[m->pacman_pos.y][m->pacman_pos.x - 1]  == 'Y') {
           m->t_map[m->pacman_pos.y][m->pacman_pos.x - 1] = m->t_map[m->pacman_pos.y][m->pacman_pos.x];
           m->t_map[m->pacman_pos.y][m->pacman_pos.x] = ' ';
           m->score_counter += 30;
           printf("Ate fruit\n");
        }
        else if (m->pacman_pos.x && m->t_map[m->pacman_pos.y][m->pacman_pos.x - 1]  == 'G') {
           m->t_map[m->pacman_pos.y][m->pacman_pos.x - 1] = m->t_map[m->pacman_pos.y][m->pacman_pos.x];
           m->t_map[m->pacman_pos.y][m->pacman_pos.x] = ' ';
           m->score_counter += 30;
           printf("Ate ghost or die\n");
        }
    }
    else if(to == RIGHT) {
        if (m->pacman_pos.x == MAP_WIDTH - 1) {
           m->t_map[m->pacman_pos.y][0] = m->t_map[m->pacman_pos.y][m->pacman_pos.x];
           m->t_map[m->pacman_pos.y][m->pacman_pos.x] = ' ';
        }
        if (m->t_map[m->pacman_pos.y][m->pacman_pos.x + 1]  == ' ') {
           m->t_map[m->pacman_pos.y][m->pacman_pos.x + 1] = m->t_map[m->pacman_pos.y][m->pacman_pos.x];
           m->t_map[m->pacman_pos.y][m->pacman_pos.x] = ' ';
        }
        else if (m->t_map[m->pacman_pos.y][m->pacman_pos.x + 1]  == '.') {
           m->t_map[m->pacman_pos.y][m->pacman_pos.x + 1] = m->t_map[m->pacman_pos.y][m->pacman_pos.x];
           m->t_map[m->pacman_pos.y][m->pacman_pos.x] = ' ';
           m->score_counter++;
           printf("Ate pils\n");
        }
        else if (m->t_map[m->pacman_pos.y][m->pacman_pos.x + 1]  == '*') {
           m->t_map[m->pacman_pos.y][m->pacman_pos.x + 1] = m->t_map[m->pacman_pos.y][m->pacman_pos.x];
           m->t_map[m->pacman_pos.y][m->pacman_pos.x] = ' ';
           m->score_counter += 10;
           printf("Ate big pils can eat ghosts\n");
        }
        else if (m->t_map[m->pacman_pos.y][m->pacman_pos.x + 1]  == 'Y') {
           m->t_map[m->pacman_pos.y][m->pacman_pos.x + 1] = m->t_map[m->pacman_pos.y][m->pacman_pos.x];
           m->t_map[m->pacman_pos.y][m->pacman_pos.x] = ' ';
           m->score_counter += 30;
           printf("Ate fruit\n");
        }
        else if (m->t_map[m->pacman_pos.y][m->pacman_pos.x + 1]  == 'G') {
           m->t_map[m->pacman_pos.y][m->pacman_pos.x + 1] = m->t_map[m->pacman_pos.y][m->pacman_pos.x];
           m->t_map[m->pacman_pos.y][m->pacman_pos.x] = ' ';
           m->score_counter += 30;
           printf("Ate ghost or die\n");
        }
    }
    else if (to == UP) {
        if (m->pacman_pos.y == 0) {
           m->t_map[MAP_HEIGHT - 1][m->pacman_pos.x] = m->t_map[m->pacman_pos.y][m->pacman_pos.x];
           m->t_map[m->pacman_pos.y][m->pacman_pos.x] = ' ';
        }
        else if (m->pacman_pos.y && m->t_map[m->pacman_pos.y - 1][m->pacman_pos.x]  == ' ') {
           m->t_map[m->pacman_pos.y - 1][m->pacman_pos.x] = m->t_map[m->pacman_pos.y][m->pacman_pos.x];
           m->t_map[m->pacman_pos.y][m->pacman_pos.x] = ' ';
        }
        else if(m->pacman_pos.y && m->t_map[m->pacman_pos.y - 1][m->pacman_pos.x]  == '.') {
           m->t_map[m->pacman_pos.y - 1][m->pacman_pos.x] = m->t_map[m->pacman_pos.y][m->pacman_pos.x];
           m->t_map[m->pacman_pos.y][m->pacman_pos.x] = ' ';
           m->score_counter++;
           printf("Ate pils\n");
        }
        else if(m->pacman_pos.y && m->t_map[m->pacman_pos.y - 1][m->pacman_pos.x]  == '*') {
           m->t_map[m->pacman_pos.y - 1][m->pacman_pos.x] = m->t_map[m->pacman_pos.y][m->pacman_pos.x];
           m->t_map[m->pacman_pos.y][m->pacman_pos.x] = ' ';
           m->score_counter += 10;
           printf("Ate big pils can eat ghosts\n");
        }
        else if(m->pacman_pos.y && m->t_map[m->pacman_pos.y - 1][m->pacman_pos.x]  == 'Y') {
           m->t_map[m->pacman_pos.y - 1][m->pacman_pos.x] = m->t_map[m->pacman_pos.y][m->pacman_pos.x];
           m->t_map[m->pacman_pos.y][m->pacman_pos.x] = ' ';
           m->score_counter += 30;
           printf("Ate fruit\n");
        }
        else if(m->pacman_pos.y && m->t_map[m->pacman_pos.y - 1][m->pacman_pos.x]  == 'G') {
           m->t_map[m->pacman_pos.y - 1][m->pacman_pos.x] = m->t_map[m->pacman_pos.y][m->pacman_pos.x];
           m->t_map[m->pacman_pos.y][m->pacman_pos.x] = ' ';
           m->score_counter += 30;
           printf("Ate ghost or die\n");
        }
    }
    else if(to == DOWN) {
        if (m->pacman_pos.y == MAP_HEIGHT -1) {
           m->t_map[0][m->pacman_pos.x] = m->t_map[m->pacman_pos.y][m->pacman_pos.x];
           m->t_map[m->pacman_pos.y][m->pacman_pos.x] = ' ';
        }
        else if(m->pacman_pos.y < MAP_HEIGHT - 1 && m->t_map[m->pacman_pos.y + 1][m->pacman_pos.x]  == ' ') {
           m->t_map[m->pacman_pos.y + 1][m->pacman_pos.x] = m->t_map[m->pacman_pos.y][m->pacman_pos.x];
           m->t_map[m->pacman_pos.y][m->pacman_pos.x] = ' ';
        }
        else if(m->pacman_pos.y < MAP_HEIGHT - 1 && m->t_map[m->pacman_pos.y + 1][m->pacman_pos.x]  == '.') {
           m->t_map[m->pacman_pos.y + 1][m->pacman_pos.x] = m->t_map[m->pacman_pos.y][m->pacman_pos.x];
           m->t_map[m->pacman_pos.y][m->pacman_pos.x] = ' ';
           printf("Ate pils\n");
        }
        else if(m->pacman_pos.y < MAP_HEIGHT - 1 && m->t_map[m->pacman_pos.y + 1][m->pacman_pos.x]  == '*') {
           m->t_map[m->pacman_pos.y + 1][m->pacman_pos.x] = m->t_map[m->pacman_pos.y][m->pacman_pos.x];
           m->t_map[m->pacman_pos.y][m->pacman_pos.x] = ' ';
           m->score_counter += 10;
           printf("Ate big pils can eat ghosts\n");
        }
        else if(m->pacman_pos.y < MAP_HEIGHT - 1 && m->t_map[m->pacman_pos.y + 1][m->pacman_pos.x]  == 'Y') {
           m->t_map[m->pacman_pos.y + 1][m->pacman_pos.x] = m->t_map[m->pacman_pos.y][m->pacman_pos.x];
           m->t_map[m->pacman_pos.y][m->pacman_pos.x] = ' ';
           m->score_counter += 30;
           printf("Ate fruit\n");
        }
        else if(m->pacman_pos.y < MAP_HEIGHT - 1 && m->t_map[m->pacman_pos.y + 1][m->pacman_pos.x]  == 'G') {
           m->t_map[m->pacman_pos.y + 1][m->pacman_pos.x] = m->t_map[m->pacman_pos.y][m->pacman_pos.x];
           m->t_map[m->pacman_pos.y][m->pacman_pos.x] = ' ';
           m->score_counter += 30;
           printf("Ate ghost or die\n");
        }

    }
}


/** the first function in early stage of developping not used anymore **/
void update(GameMap *m) {
    move_player(m);
}


