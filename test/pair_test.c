#include "stdlib.h"
#include "stdio.h"
#include "pair.h"


int main() {
	char c = 'A', s = 'B';
	int x = 5, y = 10;
	int get1, get2;
	pair p;
    
	p = pair_init(&x, &y, Int, Int);
  
    set_first(p, x);
	set_second(p, y);

	get1 = get_first(p).i;
	get2 = get_second(p).i;

	assert(get1 == x);
	assert(get2 == y);

	clear(p);

	p = pair_init(&c, &s, Char, Char);

	pair_set(p, &c, &s);

	get1 = get_first(p).c;
	get2 = get_second(p).c;

	assert(c == get1);
	assert(s == get2);

	clear(p);
  
    return 0;
}