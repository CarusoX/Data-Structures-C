#include "stack.h"

int main() {

	// Variables //
	char a = 'A', b = 'B', c = 'C';
	int x = 1, y = 2, z = 3;
	stack s;

	// Init the two stacks //
	s = stack_init(Int);
	
	// Testing push function //
	push(s, z);
	push(s, y);
	push(s, x);

	// The numbers are 1, 2, 3 //
	printf("%d, %d, %d \n", x, y, z);
	printf("Needs to be equal to: \n");

	// This should return 1, 2 and 3 //
	printf("%d, ", top(s)->value.i);
	pop(s);
	printf("%d, ", top(s)->value.i);
	pop(s);
	printf("%d, ", top(s)->value.i);

	printf("Size also should be 1: %lu \n", size(s));

	pop(s);

	// Freeing all the data allocated //
	stack_destroy(s);

	return 0;
}