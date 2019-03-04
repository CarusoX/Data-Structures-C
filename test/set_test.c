#include "set.h"
#include "defs.h"
#include "stdlib.h"
#include "stdio.h"
#include "time.h"
int main() {
    clock_t begin = clock();
    set s = set_init(Int);
    srand(time(NULL));
    fore(i, 0, 100000) {
        int r = rand() % 2;
        int l = rand();
        if(r) {
            insert(s, i);
        } else {
            erase(s, i);
        }
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%lf segundos\n", time_spent);
    printf("%d elements inside\n", size(s));
    clear(s);
    return 0;
}