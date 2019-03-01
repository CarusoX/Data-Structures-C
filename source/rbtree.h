#include "assert.h"
#include "defs.h"
#include "stdlib.h"
#include "T.h"

enum Colors {R, B};

typedef struct RBTree* tree;

/*
1) Each node is either red or black.
2) The root is black.
3) If a node is red, then both its children are black.
4) Every path from a given node to any of its descendants contains the same number of black nodes.
*/

struct RBTree {
    /* Current node data */
    typeT node;
    /* Current node color */
    int color;
    /* Left node */
    tree left;
    /* Right node */
    tree right;
    /* Parent node */
    tree parent;
};

// Create an RBTree node
tree tree_create();
// Inserte a RBTree node into another one
tree tree_insert(tree, tree);
// Returns the matching node, or where should it be attached
tree tree_find(tree, typeT);
// Erase an element
void tree_erase(tree, tree);
// Restore the violation of the 4 properties after an insert
void tree_balance(tree*, tree);

void print(tree, int);