#include "rbtree.h"
#include "stdio.h"

static inline void swap(int* a, int* b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

static tree tree_parent(tree a) {
    return a->parent;
}

static tree tree_grandparent(tree a) {
    tree p = tree_parent(a);
    if(!p) return NULL;
    return tree_parent(p);
}

static tree tree_sibling(tree a) {
    tree p = tree_parent(a);
    if(!p) return NULL;
    if(a == p->left) return p->right;
    return p->left;
}

static tree tree_uncle(tree a) {
    tree p = tree_parent(a);
    if(!p) return NULL;
    return tree_sibling(p);
}

static void tree_rotateL(tree* root, tree P) { 
    tree Q = P->right;
    P->right = Q->left;
    if(P->right != NULL) P->right->parent = P;

    if(P->parent == NULL) {
        *root = Q;
        Q->parent = NULL;
    }
    else if(P->parent->right == P) {
        P->parent->right = Q;
        Q->parent = P->parent;
    } else {
        P->parent->left = Q;
        Q->parent = P->parent;
    }

    Q->left = P;
    P->parent = Q;
}

static void tree_rotateR(tree* root, tree Q) {
    tree P = Q->left;
    Q->left = P->right;
    if(Q->left != NULL) Q->left->parent = Q;
    
    if(Q->parent == NULL) {
        *root = P;
        P->parent = NULL;
    }
    else if(Q->parent->left == Q) {
        Q->parent->left = P;
        P->parent = Q->parent;
    } else{
        Q->parent->right = P;
        P->parent = Q->parent;
    }

    P->right = Q;
    Q->parent = P;
}

tree tree_create(typeT t) {
    tree g = (tree)malloc(sizeof(struct RBTree));
    g->node = t;
    g->left = g->right = g->parent = NULL;
    g->color = R;
    return g;
}

tree tree_find(tree current, typeT t) {
    if(!current) return NULL;
    if(current->left && less_than(t, current->node)) {
        return tree_find(current->left, t);
    } else if(current->right && greater_than(t, current->node)) {
        return tree_find(current->right, t);
    }

    return current;
}

tree tree_insert(tree w, tree t) {
    if(less_than(t->node, w->node)) {
        w->left = t;
    } else {
        w->right = t;
    }
    t->parent = w;
}

void tree_balance(tree* root, tree t) {
    tree p = tree_parent(t);
    tree g = tree_grandparent(t);
    tree u = tree_uncle(t);

    // Case 1
    if(p == NULL) {
        t->color = B;
        return;
    }

    // Case 2
    if(p->color == B) {
        return;
    }

    // Case 3
    if(u != NULL && u->color == R) {
        p->color = B;
        u->color = B;
        g->color = R;
        tree_balance(root, g);
        return;
    }

    // Case 4

    /* First part */
    tree GL = g->left;
    tree GR = g->right;
    if(GL != NULL && t == GL->right) {
        tree_rotateL(root, p);
        t = t->left;
        p = tree_parent(t);
        g = tree_grandparent(t);
    } else if(GR != NULL && t == GR->left) {
        tree_rotateR(root, p);
        t = t->right;
        p = tree_parent(t);
        g = tree_grandparent(t);
    }
    
    /* Second part */
    if(t == p->left) tree_rotateR(root, g);
    else tree_rotateL(root, g);

    p->color = B;
    g->color = R;

    return;
}

void print(tree t, int space) {
    // Base case  
    if (t == NULL)  
        return;  
  
    // Increase distance between levels  
    space += 10;  
  
    // Process right child first  
    print(t->right, space);
    printf("\n"); 
    for (int i = 10; i < space; i++) printf(" ");
    printf("%d %d\n", t->node->value.i, t->color);
  
    // Process left child  
    print(t->left, space);
}
