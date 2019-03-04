#ifndef HEAP_H
#define HEAP_H

#include "T.h"

struct Heap {
	vector v;
	int type;
	size_t max_sz;
	size_t sz;

	// Allocate functions

	/* Swaps an element up to satisfy the min_heap condition */
	void (*bubble_up)(heap);
	/* Swaps an element down to satisfy the min_heap condition */
	void (*bubble_down)(heap h);
	/* Adds an element to the heap */
	void (*add)(heap, typeT);
	/* Removes the min element of the heap */
	void (*remove)(heap);
	/* Returns the position of an element's parent */
	int (*parent)(int);
	/* Returns the data of an element's parent */
	typeT (*parent_data)(heap, int);
	/* Returns the position of an element's left children */
	int (*left)(int);
	/* Returns the data of an element's left children */
	typeT (*left_data)(heap, int);
	/* Returns the position of an element's right children */
	int (*right)(int);
	/* Returns the data of an element's right children */
	typeT (*right_data)(heap, int);
	/* Swaps two elements in the tree */
	void (*swap)(heap, int, int);
	/* Returns the first element in the tree */
	typeT (*get_min)(heap);
	/* Returns the size of the heap */
	size_t (*size)(heap);
};

heap heap_init(int type, size_t max_sz);

void heap_bubble_up(heap h);

void heap_bubble_down(heap h);

void heap_add(heap h, typeT value);

void heap_remove(heap h);

int heap_parent(int pos);

typeT heap_parent_data(heap h, int pos);

int heap_left(int pos);

typeT heap_left_data(heap h, int pos);

int heap_right(int pos);

typeT heap_right_data(heap h, int pos);

void heap_swap(heap h, int pos1, int pos2);

typeT heap_get_min(heap h);

size_t heap_size(heap h);

void heap_destroy(heap h);

#endif