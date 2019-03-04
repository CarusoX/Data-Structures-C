#include "assert.h"
#include "set.h"

set set_init(int type) {
    set s = (set)malloc(sizeof(struct Set));

    // Empty tree
    s->root = NULL;

    s->type = type;
    s->sz = 0;

    // Allocate functions

    s->insert = set_insert;
    s->erase = set_erase;
    s->find = set_find;
    s->check = set_check;
    s->size = set_size;
    s->clear = set_clear;
    s->destroy = set_destroy;

    return s;
}

void set_insert(set s, void* elem) {
    // Create the struct T
    typeT t = T_init(s->type, elem);

    if(!s->sz) {
        // Empty tree
        tree node = tree_create(t);

        s->root = node;

        // Root is black
        s->root->color = B;

        s->sz++;

        return;
    }

    // Is it already?
    tree r = tree_find(s->root, t);

    if(equals(t, r->node)) {
        // Already on tree
        free(t); t = NULL;
    } else {
        // Not on set
        tree node = tree_create(t);

        // Attach node
        tree_insert(r, node);

        // Restore balance
        tree_balance(node);

        // Retrieve new root
        s->root = node;
        while(s->root->parent) s->root = s->root->parent;

        s->sz++;
    }
}

void set_erase(set s, void* elem) {
    // Create the struct T
    typeT t = T_init(s->type, elem);

    // Find element
    tree r = tree_find(s->root, t);
    
    // If set is empty or elem does not belong to s return
    if(!s->sz || !equals(r->node, t)) {
        free(t); t = NULL;
        return;
    }

    // Search is over
    free(t); t = NULL;

    tree node = r;

    // If it has 2 non leaf children, find its in-order successor
    if(r->right && r->left) {
        r = r->right;
        while(r->left) r = r->left;

        // Replace it
        node->node->iType = r->node->iType;
        node->node->value = r->node->value;

        // Now delete that node (r), which does not have a left child
    }

    // INVARIANT: Either r has 0 or 1 child //
    // The variable node will be the child of r if it has, or NULL //
    // We will replace r with node, unless node is null, in which case r wont be replaced, but will be treated as it was //

    if(r->right) node = r->right;
    else node = r->left;
    
    // If no children
    if(!node) {
        // Trivial if color is RED

        if(r->color == B) {
            tree_erase_case1(r);
        }

        // Detach node from parent
        if(r->parent) {
            if(r == r->parent->left) r->parent->left = NULL;
            else r->parent->right = NULL;
        }
        s->root = r->parent;
    } else {
        // Replace r by node
        tree_replace(r, node);

        // The problem is when both colors are black
        if(r->color == B) {
            if(node->color == R) node->color = B;
            else tree_erase_case1(node);
        }
        s->root = node;
    }

    // Find new root
    while(s->root && s->root->parent) s->root = s->root->parent;

    free(r->node); r->node = NULL;
    free(r); r = NULL;

    s->sz--;
}

tree set_find(set s, void* elem) {
    typeT t = T_init(s->type, elem);
    tree r = tree_find(s->root, t);
    if(equals(r->node, t)) {
        free(t); t = NULL;
        return r;
    }
    free(t); t = NULL;
    return NULL;
}

void set_check(set s) {
    int x = 0;
    int d = tree_check(s->root, &x, 0);
    assert(d == s->sz);
}

size_t set_size(set s) {
    return s->sz;
}

void set_clear(set s) {
    tree_clear(s->root);
    s->sz = 0;
}

void set_destroy(set s) {
    clear(s);
    free(s); s = NULL;
}

