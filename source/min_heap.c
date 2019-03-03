#include "min_heap.h"

heap heap_init(int type, size_t max_sz){
	heap h = (heap)malloc(sizeof(struct Heap));

	h->type = type;
	h->max_sz = max_sz;
	h->sz = 0;

	vector v = vector_init(type, max_sz);

	h->v = v;

	return h;
}

void heap_bubble_up(heap h){
	typeT actual = vector_at(h->v, h->sz);
	typeT parent = vector_at((h->v), heap_parent_data(h, h->sz));
	while(T_greater_than(actual, parent) && h->sz > 0 && heap_parent(h->sz) > 0){
		heap_swap(h, h->sz, heap_parent(h->sz));
		actual = parent;
		parent = heap_parent_data(h, actual);
	}
}

void heap_add(heap h, typeT value){
	(h->sz)++;
	vector_push_back(h->v, value);
	heap_bubble_up(h);
}

void heap_remove(heap h){
	
}

void heap_change_val();

int heap_parent(int pos){
	return (pos - 1) / 2;
}

typeT heap_parent_data(heap h, int pos){
	return vector_at(h->v, (pos - 1) / 2);
}

int heap_left(int pos){
	return 2 * pos + 1;
}

typeT heap_left_data(heap h, int pos){
	return vector_at(h->v, 2 * pos + 1);
}

int heap_right(int pos){
	return 2 * pos + 2;
}

typeT heap_right_data(heap h, int pos){
	return vector_at(h->v, 2 * pos + 2);
}

void heap_swap(heap h, int pos1, int pos2){
	typeT temp = vector_at(h->v, pos1);
	vector_push_at(h->v, vector_at(h->v, pos2), pos1);
	vector_push_at(h->v, temp, pos2);
}

typeT heap_get_min(heap h){
	return vector_at(h->v, 0);
}

size_t heap_size(heap h){
	return h->sz;
}

void heap_destroy(heap h){
	vector_clear(h->v);
	free(h);
}