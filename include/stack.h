#include "assert.h"
#include <stdbool.h>
#include "defs.h"
#include "stdlib.h"
#include "T.h"

typedef struct Node* node;
typedef struct Stack* stack;

// Struct containing the data of only one node //
struct Node {
	/* The data of the node */
	typeT t_node;
	/* Pointer to next element */
	node next;
};

// Struct with all the nodes //
struct Stack {
	/* First element of the stack */
	node the_stack;
    /* Number of elements stored */
    size_t sz;
	/* Type of the elements */
	int type;

	// Function pointers //

	/* Returns top element in stack */
	data (*top)(stack);
	/* Push an element in the stack */
	void (*push)(stack, void*);
	/* Pop the last element in the stack */
	void (*pop)(stack);
	/* Returns the type of the top element in the stack */
	int (*top_type)(stack);
	/* Returns true if the stack is empty */
	bool (*empty)(stack);
	/* Returns stack size */
	size_t (*size)(stack);
	/* Frees the memory used by the stack */
	void (*clear)(stack);

};

stack stack_init(int type);

void stack_push(stack s, void* elem);

void stack_pop(stack s);

data stack_top(stack s);

int stack_top_type(stack s);

bool stack_empty(stack s);

size_t stack_size(stack s);

void stack_clear(stack s);