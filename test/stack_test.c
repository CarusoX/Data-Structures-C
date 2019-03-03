#include "stdlib.h"
#include "stdio.h"
#include "stack.h"

int main() {

	// Variables //
	char a = 'A', b = 'B', c = 'C';
	int x = 1, y = 2, z = 3;
	stack s, d;

	// Init the two stacks //
	s = stack_init(Int);
	d = stack_init(Char);
	
	// Testing push function //
	push(s, z);
	push(s, y);
	push(s, x);

	push(d, a);
	push(d, b);
	push(d, c);

	// The numbers are 1, 2, 3 //
	printf("%d, %d, %d \n", x, y, z);
	printf("Needs to be equal to: \n");

	// This should return 1, 2 and 3 //
	printf("%d, ", top(s).i);
	pop(s);
	printf("%d, ", top(s).i);
	pop(s);
	printf("%d, ", top(s).i);

	// If top and pop worked, here we test top_type and size //
	printf("Type should be 3: %d", top_type(s));
	printf("Size also should be 3: %d", size(s));

	// Freeing all the data allocated //
	stack_clear(s);
	stack_clear(d);

	return 0;
}