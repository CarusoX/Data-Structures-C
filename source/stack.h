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

	// Function pointers //

	/* Returns top element in stack */
	data (*stack_top)(stack s);
	/* Push an element in the stack */
	void (*stack_push)(stack s, void* elem);
	/* Pop the last element in the stack */
	void (*stack_pop)(stack s);
	/* Returns the type of the top element in the stack */
	int (*stack_top_type)(stack s);
	/* Returns true if the stack is empty */
	bool (*stack_empty)(stack s);
	/* Returns stack size */
	size_t (*stack_size)(stack s);
	/* Frees the memory used by the stack */
	void (*stack_clear)(stack s);

};

stack stack_init();

data stack_top(stack s);

void stack_push(stack s, void* elem, int type);

void stack_pop(stack s);

int stack_top_type(stack s);

bool stack_empty(stack s);

size_t stack_size(stack s);

void stack_clear(stack s);