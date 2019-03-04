#include "stdlib.h"
#include "stdio.h"
#include "pair.h"


int main() {
	char c = 'A', s = 'B';
	int x = 5, y = 10;
	typeT get1, get2;
	pair p;
    
	p = pair_init(&x, &y, Int, Int);
  
    set_first(p, x);
	set_second(p, y);

	get1 = get_first(p);
	get2 = get_second(p);

	assert(get1->value.i == x);
	assert(get2->value.i == y);

	clear(p);

	p = pair_init(&c, &s, Char, Char);

	pair_set(p, &c, &s);

	get1 = get_first(p);
	get2 = get_second(p);

	assert(c == get1->value.c);
	assert(s == get2->value.c);

	clear(p);
  
	printf("OK");

    return 0;
}