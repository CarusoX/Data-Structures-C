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
	void (*set_pair)(pair p, void* v1, void* v2, int t1, int t2);

};

pair init_pair();

void set_first(pair p, void* value, int type);

data get_first(pair p);

int get_first_type(pair p);

void set_second(pair p, void* value, int type);

data get_second(pair p);

int get_second_type(pair p);

void set_pair(pair p, void* v1, void* v2, int t1, int t2);