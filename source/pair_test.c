#include "stdlib.h"
#include "stdio.h"
#include "pair.h"


int main() {

    pair p = pair_init();
  
	int x = 5, y = 10;
    pair_set_first(p, x, 6);
	pair_set_second(p, y, 6);

	int get1, get2;

	get1 = pair_get_first(p);
	get2 = pair_get_second(p);

	cout << x << " = " << get1 << endl;
	cout << y << " = " << get2 << endl;

	char c = 'A', s = 'B';
	pair_set(p, c, s, 3, 3);

	get1 = pair_get_first(p);
	get2 = pair_get_second(p);

	cout << c << " = " << get1 << endl;
	cout << s << " = " << get2 << endl;

	destroy_pair(p);
  
    return 0;
}