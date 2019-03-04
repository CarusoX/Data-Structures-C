#include "set.h"
#include "defs.h"
#include "stdlib.h"
#include "stdio.h"
#include "time.h"
int main() {
    clock_t begin = clock();
    set s = set_init(Int);
    srand(time(NULL));
    int x = 1, y = 2, z = 3, w = 4;
    fore(i, 0, 10000) {
        int r = rand() % 10000;
        insert(s, r);
    }
    fore(i, 0, 100000) {
        int r = rand() % 10000;
        erase(s, r);
        check(s);
    }
    destroy(s);
    return 0;
}