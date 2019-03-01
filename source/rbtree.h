#include "stdlib.h"
#include "stdio.h"
#include "assert.h"
#include "T.h"

struct RBTree {
    // Data //

    /* Current node data */
    struct T node;
    /* Current node color */
    int color;
    /* Left node */
    struct RBTree* leftChild;
    /* Right node */
    struct RBTree* rightChild;

    // Functions //

    /* Insert element */
    void (*insert)(struct RBTree*, struct T);
    /* Erase element */
    void (*erase)(struct RBTree*, struct T);
};

typedef struct RBTree* tree;

void set_insert(tree, struct T);
void set_erase(tree, struct T);
// Rotate
// Change color