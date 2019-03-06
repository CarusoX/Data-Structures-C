#include "heap.h"

heap heap_init(int type, int opt) {
	heap h = (heap)malloc(sizeof(struct Heap));

	h->type = type;

	vector v = vector_init(type, 1);
	h->v = v;

	// Allocate functions
	h->insert = heap_insert;
	h->erase = heap_erase;
	h->top = heap_top;
	h->size = heap_size;
	h->clear = heap_clear;
	h->destroy = heap_destroy;

	if(opt == MIN) {
		#undef oper
		#define oper(a, b) less_than(a, b)
	}

	return h;
}

void heap_insert(heap h, typeT value) {
	vector_push_back(h->v, value);
	heap_lift(h);
}

void heap_erase(heap h){
	heap_swap(h, 0, size(h->v) - 1);
	pop_back(h->v);
	if(size(h->v)) heap_sink(h);
}

void heap_lift(heap h) {
	int i = size(h->v) - 1;

	typeT cur = at(h->v, i);
	typeT p = heap_parent(h, i);

	while(p && oper(cur, p)) {
		heap_swap(h, i, (i - 1) / 2);
		i = (i - 1) / 2;
		cur = at(h->v, i);
		p = heap_parent(h, i);
	}
}

void heap_sink(heap h){
	int i = 0;

	typeT cur = at(h->v, i);
	typeT left = heap_left(h, i);
	typeT right = heap_right(h, i);

	while((left && oper(left, cur)) || (right && oper(right, cur))) {
		if(!right || oper(left, right)) {
			heap_swap(h, i, 2 * i + 1);
			i = 2 * i + 1;
			cur = at(h->v, i);
			left = heap_left(h, i);
			right = heap_right(h, i);
		} else {
			heap_swap(h, i, 2 * (i + 1));
			i = 2 * (i + 1);
			cur = at(h->v, i);
			left = heap_left(h, i);
			right = heap_right(h, i);
		}
	}
}

typeT heap_parent(heap h, int p) {
	if(0 < p)
		return at(h->v, (p - 1) / 2);
	else
		return NULL;
}

typeT heap_left(heap h, int p) {
	if(2 * p + 1 < size(h->v))
		return at(h->v, 2 * p + 1);
	else
		return NULL;
}

typeT heap_right(heap h, int p) {
	if(2 * (p + 1) < size(h->v))
		return at(h->v, 2 * (p + 1));
	else
		return NULL;
}

void heap_swap(heap h, int i, int j) {
	typeT t1 = copy(at(h->v, i));
	typeT t2 = copy(at(h->v, j));
	set_at(h->v, t1, j);
	set_at(h->v, t2, i);
}

typeT heap_top(heap h){
	return at(h->v, 0);
}

size_t heap_size(heap h){
	return size(h->v);
}

void heap_clear(heap h) {
	clear(h->v);
}

void heap_destroy(heap h){
	destroy(h->v);
	free(h); h = NULL;
}