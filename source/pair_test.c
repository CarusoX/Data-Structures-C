#include "stdlib.h"
#include "stdio.h"
#include "pair.h"


int main() {

	printf("Hola");

    pair p = pair_init();
  
	int x = 5, y = 10;
    pair_set_first(p, &x);
	pair_set_second(p, &y);

	int get1, get2;

	get1 = (pair_get_first(p)).i;
	get2 = (pair_get_second(p)).i;

	printf("%d = %d \n", x, get1);
	printf("%d = %d \n", y, get2);

	char c = 'A', s = 'B';
	pair_set(p, &c, &s);

	get1 = (pair_get_first(p)).c;
	get2 = (pair_get_second(p)).c;

	printf("%d = %d \n", c, get1);
	printf("%d = %d \n", s, get2);

	pair_destroy(p);
  
    return 0;
}