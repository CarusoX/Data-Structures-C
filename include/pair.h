#ifndef PAIR_H
#define PAIR_H

typedef struct T* typeT;

#include "defs.h"
#include "stdlib.h"
#include "T.h"

// Pointer to struct pair //
typedef struct Pair* pair;

struct Pair {
	// Pointers to structs T containing the data of the pair //
	typeT first, second;

	// Function pointers //

	/* Set the two elements */
	void (*set)(pair, void*, void*);
	/* Set the first element of the pair */
	void (*set_first)(pair, void*);
	/* Set the second element of the pair */
	void (*set_second)(pair, void*);
	/* Get the first element of the pair */
	typeT (*get_first)(pair);
	/* Get the second element of the pair */
	typeT (*get_second)(pair);
	/* Destroy pair */
	void (*destroy)(pair);
};

pair pair_init(int t1, int t2, void* v1, void* v2);

void pair_set(pair p, void* v1, void* v2);

void pair_set_first(pair p, void* value);

void pair_set_second(pair p, void* value);

typeT pair_get_first(pair p);

typeT pair_get_second(pair p);

void pair_destroy(pair p);

#endif