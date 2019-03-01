#include "stdlib.h"
#include "stdio.h"
#include "vector.h"

#define fore(i, s, e) for(int i = s; i < e; i++)
#define pb(v, x) push_back(&v, &x)
#define at(v, p) at(&v, p)


int main() {
    vector v;
    vector_init(&v, 3, 1);
    fore(i, 0, 30) {
        char c = i + 'a';
        v.pb(v, c);
    }
    fore(i, 0, 30) {
        struct T* t = v.at(v, i);
        printf("%d %c\n", t->iType, t->value.c);
    }
    v.clear(&v);
    return 0;
}