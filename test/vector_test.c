#include "defs.h"
#include "stdlib.h"
#include "stdio.h"
#include "vector.h"


int main() {
    vector v = vector_init(Int, 1);
    fore(i, 0, 100000) {
        push_back(v, i);
    }
    fore(i, 0, 100000) {
        struct T* t = at(v, i);
        // printf("%d\n", t->value.i);
    }
    clear(v);
    return 0;
}