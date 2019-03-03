#include "assert.h"
#include "defs.h"
#include "stdlib.h"
#include "vector.h"
#include "T.h"

typedef struct Heap* heap;

struct Heap {
	vector v;
	int type;
	size_t max_sz;
	size_t sz;

	// Allocate functions

	void (*bubble_up)(heap);

	void (*add)(heap, typeT);

	void (*remove)(heap);

	int (*parent)(int);

	typeT (*parent_data)(heap, int);

	int (*left)(int);

	typeT (*left_data)(heap, int);

	int (*right)(int);

	typeT (*right_data)(heap, int);

	void (*swap)(heap, int, int);

	typeT (*get_min)(heap);

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

