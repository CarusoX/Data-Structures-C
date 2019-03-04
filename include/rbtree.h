#ifndef RBTREE_H
#define RBTREE_H

typedef struct T* typeT;

#include "defs.h"
#include "stdlib.h"
#include "T.h"

/*
1) Each node is either red or black.
2) The root is black.
3) If a node is red, then both its children are black.
4) Every path from a given node to any of its descendants contains the same number of black nodes.
*/

enum Colors {R, B};

typedef struct RBTree* tree;

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

// Create an RBTree node //
tree tree_create();

// Inserte a RBTree node into another node //
tree tree_insert(tree, tree);

// Restore the violation of the 4 properties after an insert
void tree_balance(tree);

// Returns the matching node, or where should it be attached //
tree tree_find(tree, typeT);

// Erase tree; Has six cases //
void tree_erase_case1(tree);
void tree_erase_case2(tree);
void tree_erase_case3(tree);
void tree_erase_case4(tree);
void tree_erase_case5(tree);
void tree_erase_case6(tree);

// Replace a node with another
void tree_replace(tree, tree);

// Chech if given tree is a RBTree
int tree_check(tree, int*, int);

// Clear tree //
void tree_clear(tree);

#endif