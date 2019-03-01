#include "bst.h"

set set_init(int type) {
    set s = (set)malloc(sizeof(struct BST));
    s->bst = NULL;
    s->type = type;
    s->sz = 0;

    s->insert = set_insert;
    // s->erase = set_erase;
    // s->size = set_size;
    return s;
}

void set_insert(set s, void* elem) {
    // Create the struct
    typeT t = T_init();
    t->set_type(t, s->type);
    t->set_value(t, elem);
    // Create the node
    tree node = tree_create(t);
    // Normal bst insertion
    s->bst = tree_insert(s->bst, node);
    // Fix balance
    tree_balance(&s->bst, node);
}

