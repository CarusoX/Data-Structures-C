#include "defs.h"
#include "stdlib.h"
#include "stdio.h"
#include "vector.h"
#include "pair.h"


int main() {
    vector v = vector_init(Pair, 1);
    fore(i, 0, 100000) {
        int u = i + 1, z = i + 2;
        pair p = pair_init(&u, &z, Int, Int);
        push_back(v, p);
    }
    printf("%d", v->type);
    fore(i, 0, 100000) {
        struct T* t = at(v, i);
        data d1 = get_first(t->value.p);
        data d2 = get_second(t->value.p);
        printf("%d %d\n", d1, d2);
    }
    clear(v);
    return 0;
}