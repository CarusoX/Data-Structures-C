
#include "pair.h"


int main() {
	char c = 'A', s = 'B';
	int x = 5, y = 10;
	typeT get1, get2;
	pair p;
    
	p = pair_init(Int, Int, &x, &y);
  
    set_first(p, x);
	set_second(p, y);

	get1 = get_first(p);
	get2 = get_second(p);

	destroy(p);

	p = pair_init(Char, Char, &c, &s);

	set(p, c, s);

	get1 = get_first(p);
	get2 = get_second(p);

	destroy(p);
  
	printf("OK\n");

    return 0;
}