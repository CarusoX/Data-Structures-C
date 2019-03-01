#include "bst.h"
#include "defs.h"
#include "stdlib.h"
#include "stdio.h"

int main() {
    set s = set_init(1);
    fore(i, 0, 20) {
        insert(s, i);
    }
    print(s->bst, 0);
    return 0;
}