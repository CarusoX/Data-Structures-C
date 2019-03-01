#include "rbtree.h"

static void swap(int* a, int* b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

static tree tree_parent(tree a) {
    return a->parent;
}

static tree tree_grandparent(tree a) {
    tree p = tree_parent(a);
    if(p == NULL) return NULL;
    return tree_parent(p);
}

static tree tree_sibling(tree a) {
    tree p = tree_parent(a);
    if(p == NULL) return NULL;
    if(a == p->leftChild) return p->rightChild;
    return p->leftChild;
}

static tree tree_uncle(tree a) {
    tree p = tree_parent(a);
    if(p == NULL) return p;
    return tree_sibling(p);
}

tree tree_create(typeT t) {
    tree g = (tree)malloc(sizeof(struct RBTree));
    g->node = T_init();
    g->node->iType = t->iType;
    g->node->value = t->value;
    g->leftChild = g->rightChild = g->parent = NULL;
    g->color = RED;
    return g;
}

tree tree_insert(tree current, tree t) {
    if(current == NULL) {
        printf("DONE\n");
        return t;
    }
    if(current->parent != NULL) printf("I AM AT VERTEX: %d %d and it parent is: %d\n", current->node->value.i, current->color, current->parent->node->value.i);
    else printf("I AM AT VERTEX: %d %d and it parent is: NULL\n", current->node->value.i, current->color);
    if(t->node->less_than(t->node, (current->node))) {
        current->leftChild = tree_insert(current->leftChild, t);
        current->leftChild->parent = current;
    } else if(t->node->greater_than(t->node, (current->node))) {
        current->rightChild = tree_insert(current->rightChild, t);
        current->rightChild->parent = current;
    }
    return current;
}

static void tree_rotateLeft(tree* root, tree P) { 
    tree Q = P->rightChild;
    P->rightChild = Q->leftChild;
    if(P->rightChild != NULL) P->rightChild->parent = P;

    if(P->parent == NULL) {
        *root = Q;
        Q->parent = NULL;
    }
    else if(P->parent->rightChild == P) {
        P->parent->rightChild = Q;
        Q->parent = P->parent;
    } else {
        P->parent->leftChild = Q;
        Q->parent = P->parent->leftChild;
    }

    Q->leftChild = P;
    P->parent = Q;
}

static void tree_rotateRight(tree* root, tree Q) {
    tree P = Q->leftChild;
    Q->leftChild = P->rightChild;
    if(Q->leftChild != NULL) Q->leftChild->parent = Q;
    
    if(Q->parent == NULL) {
        *root = P;
        P->parent = NULL;
    }
    else if(Q->parent->leftChild == Q) {
        Q->parent->leftChild = P;
        P->parent = Q->parent;
    } else{
        Q->parent->rightChild = P;
        P->parent = Q->parent->rightChild;
    }

    P->rightChild = Q;
    Q->parent = P;
}

void tree_balance(tree* root, tree t) {
    tree parent = tree_parent(t);
    tree grandparent = tree_grandparent(t);
    tree uncle = tree_uncle(t);

    // Case 1
    if(parent == NULL) {
        t->color = BLACK;
        return;
    }

    // Case 2
    if(parent->color == BLACK) {
        return;
    }

    // Case 3
    if(uncle != NULL && uncle->color == RED) {
        parent->color = BLACK;
        uncle->color = BLACK;
        grandparent->color = RED;
        tree_balance(root, grandparent);
        return;
    }

    // Case 4

    /* First part */
    tree GL = grandparent->leftChild;
    tree GR = grandparent->rightChild;
    if(GL != NULL && t == GL->rightChild) {
        tree_rotateLeft(root, parent);
        t = t->leftChild;
    } else if(GR != NULL && t == GR->leftChild) {
        tree_rotateRight(root, parent);
        t = t->rightChild;
    }
    
    /* Second part */
    if(t == parent->leftChild) tree_rotateRight(root, grandparent);
    else tree_rotateLeft(root, grandparent);

    parent->color = BLACK;
    grandparent->color = RED;

    return;
}

