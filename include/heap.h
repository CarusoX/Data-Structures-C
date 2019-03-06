#ifndef HEAP_H
#define HEAP_H

#include "T.h"

#define MAX 0
#define MIN 1

#define oper(a, b) greater_than(a, b)

struct Heap {
	vector v;
	int type;

	// Allocate functions

	/* Adds an element to the heap */
	void (*insert)(heap, typeT);
	/* Removes the min element of the heap */
	void (*erase)(heap);
	/* Returns the first element in the tree */
	typeT (*top)(heap);
	/* Returns the size of the heap */
	size_t (*size)(heap);
	/* Clear heap */
	void (*clear)(heap);
	/* Destroy heap */
	void (*destroy)(heap);
};

heap heap_init(int, int);

void heap_insert(heap, typeT);

void heap_erase(heap);

void heap_lift(heap);

void heap_sink(heap);

typeT heap_parent(heap, int);

typeT heap_left(heap, int);

typeT heap_right(heap, int);

void heap_swap(heap, int, int);

typeT heap_top(heap);

size_t heap_size(heap);

void heap_clear(heap);

void heap_destroy(heap);

#endif