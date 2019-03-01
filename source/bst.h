#include "stdlib.h"
#include "stdio.h"
#include "assert.h"

struct BST {
    // Data //

    /* Pointer to tree */
    struct RBTree* bst;
    /* Data type */
    int type;
    /* Size of tree */
    size_t sz;

    // Functions //

    /* Insert element */
    void (*insert)(struct BST*, void*);
    /* Erase element */
    void (*erase)(struct BST*, void*);
    /* Get size */
    void (*size)(struct BST*);
};

typedef struct BST* set;

set set_init(int, size_t);
void set_insert(set, void*);
void set_erase(set, void*);
size_t set_size(set);