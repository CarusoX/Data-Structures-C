#include "stdlib.h"
#include "stdio.h"
#include "stack.h"

int main() {

	// Variables //
	char a = 'A', b = 'B', c = 'C';
	int x = 1, y = 2, z = 3;
	stack s, c;

	// Init the two stacks //
	s = stack_init(Int);
	c = stack_init(Char);
	
	// Testing push function //
	stack_push(s, z);
	stack_push(s, y);
	stack_push(s, x);

	stack_push(c, a);
	stack_push(c, b);
	stack_push(c, c);

	// The numbers are 1, 2, 3 //
	printf("%d, %d, %d \n", x, y, z);
	printf("Needs to be equal to: \n");

	// This should return 1, 2 and 3 //
	printf("%d, ", stack_top(s).i);
	stack_pop(s);
	printf("%d, ", stack_top(s).i);
	stack_pop(s);
	printf("%d, ", stack_top(s).i);

	// If top and pop worked, here we test top_type and size //
	printf("Type should be 3: %d", stack_top_type(s));
	printf("Size also should be 3: %d", stack_size(s));

	// Freeing all the data allocated //
	stack_clear(s);
	stack_clear(c);

	return 0;
}