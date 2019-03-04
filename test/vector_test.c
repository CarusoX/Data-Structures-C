#include "vector.h"
#include "pair.h"

int main() {
    vector v = vector_init(Vector, 1);
    fore(i, 0, 10) {
        vector j = vector_init(Pair, 1);
        push_back(v, j);
    }
    fore(i, 0, 10) {
        typeT t = at(v, i);
        vector s = (t->value.v);
        fore(j, 0, 10) {
            pair p = pair_init(Int, Int, &i, &j);
            push_back(s, p);
        }
    }
    fore(i, 0, 10) {
        typeT t = at(v, i);
        vector s = (t->value.v);
        fore(j, 0, 10) {
            typeT u = at(s, j);
            pair p = u->value.p;
            typeT fst = get_first(p), snd = get_second(p);
            printf("|%d-%d|", fst->value.i, snd->value.i);
        }
        printf("\n");
    }
    destroy(v);
    return 0;
}