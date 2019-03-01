#include "stdlib.h"
#include "stdio.h"
#include "vector.h"

#include "defs.h"


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