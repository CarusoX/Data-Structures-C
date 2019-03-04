#ifndef STACK_H
#define STACK_H

#include "T.h"

// Struct with all the nodes //
struct Stack {
	/* First element of the stack */
	list first;
    /* Number of elements stored */
    size_t sz;
	/* Type of the elements */
	int type;

	// Function pointers //

	/* Returns top element in stack */
	typeT (*top)(stack);
	/* Push an element in the stack */
	void (*push)(stack, void*);
	/* Pop the last element in the stack */
	void (*pop)(stack);
	/* Returns the type of the stack */
	int (*stype)(stack);
	/* Returns true if the stack is empty */
	int (*empty)(stack);
	/* Returns stack size */
	size_t (*size)(stack);
	/* Frees the memory used by the stack */
	void (*clear)(stack);

};

stack stack_init(int type);

void stack_push(stack s, void* elem);

void stack_pop(stack s);

typeT stack_top(stack s);

int stack_type(stack s);

int stack_empty(stack s);

size_t stack_size(stack s);

void stack_clear(stack s);

void stack_destroy(stack s);

#endif