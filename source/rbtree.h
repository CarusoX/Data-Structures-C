#include "stdlib.h"
#include "stdio.h"
#include "assert.h"
#include "T.h"

enum Colors {RED, BLACK};

typedef struct RBTree* tree;

struct RBTree {
    /* Current node data */
    struct T* node;
    /* Current node color */
    int color;
    /* Left node */
    tree leftChild;
    /* Right node */
    tree rightChild;
    /* Parent node */
    tree parent;
};

tree tree_create();
tree tree_insert(tree, tree);
void tree_erase(tree, tree);
void tree_balance(tree*, tree);