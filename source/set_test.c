#include "stdlib.h"
#include "stdio.h"
#include "bst.h"

#include "defs.h"

int main() {
    set s = set_init(1);
    fore(i, 0, 20) {
        int j = 0;
        if(i % 2) j = i;
        else j = -i;
        insert(s, j);
        printf("\n");
    }
    return 0;
}