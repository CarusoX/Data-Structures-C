#include "min_heap.h"

int main(){

	int x, y, z, w;
	x = 1; y = 2; z = 3; w = 4;
	
	// Functions Test //
	heap h = heap_init(Int, MIN);
	insert(h, x);
	insert(h, y);
	insert(h, z);
	insert(h, w);

	printf("Size is: %d\n", heap_size(h));

	printf("And the elements are: ");
	printf("%d, ", top(h)->value.i);
	heap_erase(h);
	printf("%d, ", top(h)->value.i);
	heap_erase(h);
	printf("%d, ", top(h)->value.i);
	heap_erase(h);
	printf("%d\n", top(h)->value.i);
	heap_erase(h);

	destroy(h);

	return 0;
}