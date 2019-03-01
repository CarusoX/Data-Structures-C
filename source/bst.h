#include "stdlib.h"
#include "stdio.h"
#include "assert.h"
#include "rbtree.h"

typedef struct BST* set;

struct BST {
    // Data //

    /* Pointer to tree */
    tree bst;
    /* Data type */
    int type;
    /* Size of tree */
    size_t sz;

    // Functions //

    /* Insert element */
    void (*insert)(set, void*);
    /* Erase element */
    void (*erase)(set, void*);
    /* Get size */
    size_t (*size)(set);
};

set set_init(int);
void set_insert(set, void*);
void set_erase(set, void*);
size_t set_size(set);