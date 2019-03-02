#include "assert.h"
#include <stdbool.h>
#include "defs.h"
#include "stdlib.h"
#include "T.h"

typedef struct node* p_node;
typedef struct stack* p_stack;

// Struct containing the data of only one node //
struct node {
	/* The data of the node */
	typeT t_node;
	/* Pointer to next element */
	p_node next;
} node;

// Struct with all the nodes //
struct stack {
	/* First element of the stack */
	p_node the_stack;
    /* Number of elements stored */
    size_t sz;

	// Function pointers //

	/* Create the stack */
	p_stack (*stack_init)(void);
	/* Returns top element in stack */
	data (*stack_top)(p_stack s);
	/* Push an element in the stack */
	void (*stack_push)(p_stack s, void* elem);
	/* Pop the last element in the stack */
	void (*stack_pop)(p_stack s);
	/* Returns true if the stack is empty */
	bool (*stack_empty)(p_stack s);
	/* Returns stack size */
	size_t (*stack_size)(p_stack s);
	/* Frees the memory used by the stack */
	void (*stack_clear)(p_stack s);

} stack;

p_stack stack_init();

data stack_top(p_stack s);

void stack_push(p_stack s, void* elem);

void stack_pop(p_stack s);

bool stack_empty(p_stack s);

size_t stack_size(p_stack s);

void stack_clear(p_stack s);