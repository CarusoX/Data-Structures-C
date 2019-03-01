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
    // Create the struct T
    typeT t = T_init(s->type, elem);
    // Is it already?
    tree res = tree_find(s->bst, t);

    if(!res) {
        // Empty tree
        tree node = tree_create(t);
        s->bst = node;
        tree_balance(&s->bst, node);
        s->sz++;
    } else if(!t->equals(t, res->node)) {
        tree node = tree_create(t);
        tree_insert(res, node);
        tree_balance(&s->bst, node);
        s->sz++;
    } else if(t->equals(t, res->node)) free(t);
}

tree set_find(set s, void * elem) {
    typeT t = T_init(s->type, elem);
    tree res = tree_find(s->bst, t);
    if(res->node->equals(res->node, t)) {
        free(t);
        return res;
    }
    free(t);
    return NULL;
}

