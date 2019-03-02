#include "bst.h"
#include "defs.h"
#include "stdlib.h"
#include "stdio.h"
#include "time.h"
int main() {
    clock_t begin = clock();
    set s = set_init(1);
    srand(time(NULL));
    fore(i, 0, 100000) {
        int r = rand() % 100000;
        insert(s, i);
    }
    fore(i, 0, 100000) {
        int r = rand() % 100000;
        erase(s, i);
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%lf segundos\n", time_spent);
    printf("%d elements inside\n", size(s));
    return 0;
}