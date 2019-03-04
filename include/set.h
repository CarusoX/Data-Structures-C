#ifndef SET_H
#define SET_H

#include "T.h"

struct Set {
    // Data //

    /* Pointer to an RBTree */
    tree root;
    /* Data type */
    int type;
    /* Size of tree */
    size_t sz;

    // Functions //

    /* Insert element */
    void (*insert)(set, void*);
    /* Erase element */
    void (*erase)(set, void*);
    /* Finds element and returns pointer to it, NULL otherwise */
    tree (*find)(set, void*);
    /* Check if set is balanced according to RBTree */
    void (*check)(set);
    /* Get size */
    size_t (*size)(set);
    /* Clear set */
    void (*clear)(set);
    /* Destroy set */
    void (*destroy)(set);
};

set set_init(int);

void set_insert(set, void*);

void set_erase(set, void*);

tree set_find(set, void*);

void set_check(set);

size_t set_size(set);

void set_clear(set);

void set_destroy(set);

#endif