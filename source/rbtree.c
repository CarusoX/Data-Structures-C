#include "rbtree.h"
#include "stdio.h"

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

static void tree_rotateL(tree P) { 
    tree Q = P->right;
    P->right = Q->left;
    if(P->right != NULL) P->right->parent = P;

    if(P->parent == NULL) {
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

static void tree_rotateR(tree Q) {
    tree P = Q->left;
    Q->left = P->right;
    if(Q->left != NULL) Q->left->parent = Q;
    
    if(Q->parent == NULL) {
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

void tree_clear(tree cur) {
    if(!cur) return;
    tree_clear(cur->left);
    tree_clear(cur->right);
    free(cur->node);
    free(cur);
}

tree tree_insert(tree p, tree c) {
    if(less_than(c->node, p->node)) {
        p->left = c;
    } else {
        p->right = c;
    }
    c->parent = p;
}

void tree_erase_case1(tree n) {
    if(n->parent) {
        tree_erase_case2(n);
    }
}

void tree_erase_case2(tree n) {
    tree s = tree_sibling(n);

    if(s != NULL && s->color == R) {
        n->parent->color = R;
        s->color = B;
        if(n == n->parent->left) tree_rotateL(n->parent);
        else tree_rotateR(n->parent);
    }
    tree_erase_case3(n);
}

void tree_erase_case3(tree n) {
    tree s = tree_sibling(n);

    if((n->parent->color == B) && (!s || s->color == B) && (!s || !s->left || s->left->color == B) && (!s || !s->right || s->right->color == B)) {
        if(s) s->color = R;
        tree_erase_case1(n->parent);
    } else {
        tree_erase_case4(n);
    }
}

void tree_erase_case4(tree n) {
    tree s = tree_sibling(n);

    if((n->parent->color == R) && (!s || s->color == B) && (!s || !s->left || s->left->color == B) && (!s || !s->right || s->right->color == B)) {
        if(s) s->color = R;
        n->parent->color = B;
    } else {
        tree_erase_case5(n);
    }
}

void tree_erase_case5(tree n) {
    tree s = tree_sibling(n);

    if(s && s->color == B) {
        if ((n == n->parent->left) && (!s->right || s->right->color == B) && (s->left && s->left->color == R)) {
            if(s) s->color = R;
            if(s && s->left) s->left->color = B;
            tree_rotateR(s);
        } else if ((n == n->parent->right) && (!s->left || s->left->color == B) && (s->right && s->right->color == R)) {
            if(s) s->color = R;
            if(s && s->right) s->right->color = B;
            tree_rotateL(s);
        }
    }
    tree_erase_case6(n);
}

void tree_erase_case6(tree n)
{
    tree s = tree_sibling(n);

    if(s) s->color = n->parent->color;
    n->parent->color = B;

    if (n == n->parent->left) {
        if(s && s->right) s->right->color = B;
        tree_rotateL(n->parent);
    } else {
        if(s && s->left) s->left->color = B;
        tree_rotateR(n->parent);
    }
}

void tree_balance(tree t) {
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
        tree_balance(g);
        return;
    }

    // Case 4

    /* First part */
    tree GL = g->left;
    tree GR = g->right;
    if(GL != NULL && t == GL->right) {
        tree_rotateL(p);
        t = t->left;
        p = tree_parent(t);
        g = tree_grandparent(t);
    } else if(GR != NULL && t == GR->left) {
        tree_rotateR(p);
        t = t->right;
        p = tree_parent(t);
        g = tree_grandparent(t);
    }
    
    /* Second part */
    if(t == p->left) tree_rotateR(g);
    else tree_rotateL(g);

    p->color = B;
    g->color = R;

    return;
}

void tree_replace(tree t, tree s) {
    s->parent = t->parent;
    if(t->parent) {
        if(t == t->parent->left) t->parent->left = s;
        else t->parent->right = s;
    }
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

int tree_checker(tree t, int* c, int d) {
    int r = 0;
    if(t == NULL) {
        if(*c == 0) *c = d;
        else assert(*c == d);
        return r;
    }
    r = 1;
    if(t->color == R) {
        if(t->left) assert(t->left->color != R);
        if(t->right) assert(t->right->color != R);
        r += tree_checker(t->left, c, d);
        r += tree_checker(t->right, c, d);
    } else {
        r += tree_checker(t->left, c, d + 1);
        r += tree_checker(t->right, c, d + 1);
    }
    return r;
}