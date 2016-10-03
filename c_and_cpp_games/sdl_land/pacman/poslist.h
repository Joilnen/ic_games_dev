#ifndef POSLIST_H
#define POSLIST_H

#include <stdlib.h>

typedef struct _List {
    unsigned short value;
    struct _List *next, *prev;
} List;

List *create_poslist(short value);
void delete_poslist(List *head);
void add_poslist_node(List *head, List *node);
void inc_pos(List *head, unsigned short *p);
void dec_pos(List *head, unsigned short *p);

#endif
