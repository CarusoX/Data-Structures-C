#include "stdlib.h"
#include "stdio.h"
#include "vector.h"

#define fore(i, s, e) for(int i = s; i < e; i++)
#define pb(v, x) v->push_back(v, &x)
#define at(v, p) v->at(v, p)
#define clear(v) v->clear(v)


int main() {
    vector v = vector_init(3, 1);
    fore(i, 0, 30) {
        char c = i + 'a';
        pb(v, c);
    }
    fore(i, 0, 30) {
        struct T* t = at(v, i);
        printf("%d %c\n", t->iType, t->value.c);
    }
    clear(v);
    return 0;
}