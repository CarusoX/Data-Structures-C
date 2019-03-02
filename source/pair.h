#include "assert.h"
#include "defs.h"
#include "stdlib.h"
#include "T.h"

// Pointer to struct pair //
typedef struct pair* p_pair;

struct pair {
	// Pointers to structs T containing the data of the pair //
	typeT first, second;

	// Function pointers //

	/* Create the structure */
	p_pair (*init_pair)();
	/* Set the first element of the pair */
	void (*set_first)(p_pair p, void* value);
	/* Get the first element of the pair */
	data (*get_first)(p_pair p);
	/* Set the second element of the pair */
	void (*set_second)(p_pair p, void* value);
	/* Get the second element of the pair */
	data (*get_second)(p_pair p);

} pair;

p_pair init_pair();
void set_first(p_pair p, void* value);
data get_first(p_pair p);
void set_second(p_pair p, void* value);
data get_second(p_pair p);