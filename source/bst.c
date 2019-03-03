#include "bst.h"

set set_init(int type) {
    set s = (set)malloc(sizeof(struct BST));
    s->bst = NULL;
    s->type = type;
    s->sz = 0;

    s->insert = set_insert;
    s->erase = set_erase;
    s->find = set_find;
    s->clear = set_clear;
    s->size = set_size;
    return s;
}

void set_insert(set s, void* elem) {
    // Create the struct T
    typeT t = T_init(s->type, elem);

    // Is it already?
    tree res = tree_find(s->bst, t);

    if(!s->sz) {
        // Empty tree
        tree node = tree_create(t);

        s->bst = node;

        // Root is black
        s->bst->color = B;

        s->sz++;
    } else if(equals(t, res->node)) {
        // Already on tree
        free(t);
    } else {
        // Not on set
        tree node = tree_create(t);

        // Attach node
        tree_insert(res, node);

        // Restore balance
        tree_balance(node);

        // Retrieve possible new root
        s->bst = node;
        while(s->bst->parent) s->bst = s->bst->parent;

        s->sz++;
    }
}

void set_erase(set s, void* elem) {
    // Create the struct T
    typeT t = T_init(s->type, elem);

    // Find element
    tree r = tree_find(s->bst, t);
    
    // If set is empty or elem does not belong to s return
    if(!r || !equals(r->node, t)) {
        free(t);
        return;
    }

    free(t);

    tree node = r;

    // If it has 2 non leaf children
    if(r->right && r->left) {
        // Find its in-order successor
        r = r->right;
        while(r->left) r = r->left;

        // Replace it
        node->node->iType = r->node->iType;
        node->node->value = r->node->value;

        // Now delete that node (r), which does not have a left child
    }

    // INVARIANT: Either r has 0 or 1 child //
    // node will be the child of r, or NULL //
    // We will replace r with node, unless node is null, in which case r wont be replaced, but will be treated as it was //

    if(r->right) node = r->right;
    else node = r->left;
    
    // If no children
    if(!node) {
        // Trivial if color is RED

        if(r->color == B) {
            tree_erase_case1(r);
        }
        if(r->parent) {
            if(r == r->parent->left) r->parent->left = NULL;
            else r->parent->right = NULL;
        }
        s->bst = r->parent;
    } else {
        // Replace r by node
        tree_replace(r, node);

        // The only problem is when both colors are black
        if(r->color == B) {
            if(node->color == R) node->color = B;
            else tree_erase_case1(node);
        }
        s->bst = node;
    }

    while(s->bst && s->bst->parent) s->bst = s->bst->parent;

    free(r->node);
    free(r);
    s->sz--;
}

tree set_find(set s, void * elem) {
    typeT t = T_init(s->type, elem);
    tree res = tree_find(s->bst, t);
    if(equals(res->node, t)) {
        free(t);
        return res;
    }
    free(t);
    return NULL;
}

void set_clear(set s) {
    tree_clear(s->bst);
    free(s);
}

void set_checker(set s) {
    int x = 0;
    int d = tree_checker(s->bst, &x, 0);
    assert(d == s->sz);
}

size_t set_size(set s) {
    return s->sz;
}

