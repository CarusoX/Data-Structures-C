#include "stdlib.h"
#include "stdio.h"
#include "pair.h"


int main() {

    pair p = init_pair();
  
	int x = 5, y = 10;
    set_first(p, x, 6);
	set_second(p, y, 6);

	int get1, get2;

	get1 = get_first(p);
	get2 = get_second(p);

	cout << x << " = " << get1 << endl;
	cout << y << " = " << get2 << endl;

	char c = 'A', s = 'B';
	set_pair(p, c, s, 3, 3);

	get1 = get_first(p);
	get2 = get_second(p);

	cout << c << " = " << get1 << endl;
	cout << s << " = " << get2 << endl;

	destroy_pair(p);
  
    return 0;
}