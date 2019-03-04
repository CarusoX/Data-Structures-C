#include "set.h"

int main() {
    clock_t begin = clock();
    set s = set_init(Int);
    srand(time(NULL));
    int x = 1, y = 2, z = 3, w = 4;
    fore(i, 0, 10000) {
        int r = rand() % 10000;
        insert(s, r);
    }
    fore(i, 0, 10000) {
        int r = rand() % 10000;
        erase(s, r);
        check(s);
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%lf segundos\n", time_spent);
    printf("%lu elements inside\n", size(s));
    destroy(s);
    return 0;
}