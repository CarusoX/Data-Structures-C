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
	void (*push)(stack, typeT);
	/* Pop the last element in the stack */
	void (*pop)(stack);
	/* Returns true if the stack is empty */
	int (*empty)(stack);
	/* Returns stack size */
	size_t (*size)(stack);
	/* Frees the memory used by the stack */
	void (*clear)(stack);

};

stack stack_init(int type);

void stack_push(stack, typeT);

void stack_pop(stack);

typeT stack_top(stack);

int stack_empty(stack);

size_t stack_size(stack);

void stack_clear(stack);

void stack_destroy(stack);

#endif