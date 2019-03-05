#include "stack.h"

stack stack_init(int type) {

	stack s = (stack)malloc(sizeof(struct Stack));
	
	s->first = NULL;
	s->type = type;
	s->sz = 0;

	// Allocate functions
	s->top = stack_top;
	s->push = stack_push;
	s->pop = stack_pop;
	s->empty = stack_empty;
	s->size = stack_size;
	s->clear = stack_clear;

	return s;
}

void stack_push(stack s, typeT t) {
	assert(s != NULL);
	list n = (list)malloc(sizeof(struct List));
	n->elem = t;
	n->next = s->first;
	s->first = n;
	s->sz++;
}

void stack_pop(stack s) {
	assert(s != NULL);
	list n = s->first;
	s->first = n->next;
	destroy(n->elem);
	free(n); n = NULL;
	s->sz--;
}

typeT stack_top(stack s) {
	assert(s != NULL);
	return s->first->elem;
}

size_t stack_size(stack s) {
	assert(s != NULL);
	return s->sz;
}

int stack_empty(stack s) {
	assert(s != NULL);
	return (s->sz == 0);
}

void stack_clear(stack s) {
	fore(i, 0, s->sz) pop(s);
}

void stack_destroy(stack s) {
	clear(s);
	free(s); s = NULL;
}