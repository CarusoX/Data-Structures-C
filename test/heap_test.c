#include "min_heap.h"

int main(){

	int x, y, z, w;
	x = 1; y = 2; z = 3; w = 4;
	
	// Functions Test //
	heap h = heap_init(Int, 10);
	heap_add(h, x);
	heap_add(h, y);
	heap_add(h, z);
	heap_add(h, w);

	printf("Size is: %d\n", heap_size(h));

	printf("And the elements are: ");
	printf("%d, ", heap_get_min(h));
	heap_remove(h);
	printf("%d, ", heap_get_min(h));
	heap_remove(h);
	printf("%d, ", heap_get_min(h));
	heap_remove(h);
	printf("%d\n", heap_get_min(h));
	heap_remove(h);

	heap_destroy(h);

	return 0;
}