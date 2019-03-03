#include "assert.h"
#include "defs.h"
#include "stdlib.h"
#include "T.h"

// Pointer to struct pair //
typedef struct Pair* pair;

struct Pair {
	// Pointers to structs T containing the data of the pair //
	typeT first, second;

	// Function pointers //

	/* Set the first element of the pair */
	void (*set_first)(pair p, void* value);
	/* Get the first element of the pair */
	data (*get_first)(pair p);
	/* Get the type of the first element */
	int (*get_first_type)(pair p);
	/* Set the second element of the pair */
	void (*set_second)(pair p, void* value);
	/* Get the second element of the pair */
	data (*get_second)(pair p);
	/* Get the type of the second element */
	int (*get_second_type)(pair p);
	/* Set the two elements */
	void (*set)(pair p, void* v1, void* v2, int t1, int t2);

};

pair pair_init();

pair pair_create(void* v1, void* v2, int t1, int t2);

void pair_set(pair p, void* v1, void* v2);

void pair_set_first(pair p, void* value);

data pair_get_first(pair p);

int pair_get_first_type(pair p);

void pair_set_second(pair p, void* value);

data pair_get_second(pair p);

int pair_get_second_type(pair p);

void pair_destroy (pair p);