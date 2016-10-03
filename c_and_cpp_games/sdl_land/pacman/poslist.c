#include "poslist.h"

List *create_poslist(short value) {
    List *l = (List*) malloc(sizeof(List));
    l->value = value;
    l->next = l->prev = NULL;
    return l;
}

void delete_poslist(List *head) {
    List *tmp = head->next;
    while(tmp) {
        free(head);
        head = tmp;
        tmp = tmp->next;
    }
}

void add_poslist_node(List *head, List *node) {
    List *tmp = head;
    while(tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = (List*) malloc(sizeof(List));
    tmp->next->next = NULL;
    tmp->next->next->prev = tmp->next;
}


void inc_pos(List *head, unsigned short *p) {
    List *tmp = head;
    short c = 0;
    do {
        if(tmp->value == *p) {
            *p = tmp->next->value;
            break;
        }
        ++c; if(c > 40) break;
    } while(tmp = tmp->next);
}

void dec_pos(List *head, unsigned short *p) {

    List *tmp = head;
    short c = 0, vtmp;
    while(tmp->next && c < 40) {
        vtmp = tmp->value;
        tmp = tmp->next;
        if(!tmp) break;
        if(tmp->value == *p) {
            *p = vtmp;
            break;
        }
        ++c;
    }

    if(!c && c > 40) *p = head->value;
}

