#include "stdlib.h"
#include "stdio.h"
#include "pair.h"


int main() {

	// Variables //
	char c = 'A', s = 'B';
	int x = 5, y = 10;
	int get1, get2;
	pair p;
    
	// Testing creation of a pair //
	p = pair_init(Int, Int);
  
	// Testing set functions for first and second element //
    pair_set_first(p, &x);
	pair_set_second(p, &y);

	// Testing get function to know if set is working //
	get1 = (pair_get_first(p)).i;
	get2 = (pair_get_second(p)).i;

	// If the values are equal, the set and get functions are working great //
	printf("%d = %d \n", x, get1);
	printf("%d = %d \n", y, get2);

	// Init p again to test it with chars //
	p = pair_init(Char, Char);

	// Testing pair set to put the two values //
	pair_set(p, &c, &s);

	// Getting the values from the pair //
	get1 = (pair_get_first(p)).c;
	get2 = (pair_get_second(p)).c;

	// Testing if they're right //
	printf("%d = %d \n", c, get1);
	printf("%d = %d \n", s, get2);

	// Destroying the pair to free the memory allocated //
	pair_destroy(p);
  
    return 0;
}