#include "stdlib.h"
#include "stdio.h"
#include "pair.h"


int main() {

    pair p = pair_init();
  
	int x = 5, y = 10;
    pair_set_first(p, x, 6);
	pair_set_second(p, y, 6);

	int* get1, get2;

	get1 = *(int*)pair_get_first(p);
	get2 = *(int*)pair_get_second(p);

	printf("%d = %d \n", x, get1);
	printf("%d = %d \n", y, get2);

	char c = 'A', s = 'B';
	pair_set(p, c, s, 3, 3);

	get1 = *(int*)pair_get_first(p);
	get2 = *(int*)pair_get_second(p);

	printf("%d = %d \n", c, get1);
	printf("%d = %d \n", s, get2);

	destroy_pair(p);
  
    return 0;
}