#include "stack.h"

stack stack_init(int type){

	stack s = (stack)malloc(sizeof(struct Stack));
	
	s->first = NULL;
	s->type = type;
	s->sz = 0;

	// Allocate functions
	s->top = stack_top;
	s->push = stack_push;
	s->pop = stack_pop;
	s->top_type = stack_top_type;
	s->empty = stack_empty;
	s->size = stack_size;
	s->clear = stack_clear;

	return s;
}

void stack_push(stack s, void* elem){
	assert(s != NULL);
	list n = (list)malloc(sizeof(struct StackList));
	typeT t = T_init(s->type, elem);
	n -> elem = t;
	n -> next = NULL;
	(s -> sz)++;
}

void stack_pop(stack s){
	assert(s != NULL);
	list n = s -> first;
	s -> first = n -> next;
	n -> next = NULL;
	free(n);
	(s -> sz)--;
}

data stack_top(stack s){
	assert(s != NULL);
	return T_get_value((s -> first) -> elem);
}

int stack_top_type(stack s){
	assert(s != NULL);
	return T_get_type(s->first->elem);
}

size_t stack_size(stack s){
	assert(s != NULL);
	return s -> sz;
}

bool stack_empty(stack s){
	assert(s != NULL);
	return (s->sz == 0);
}

void stack_clear(stack s){
	fore(i, 0, s->sz) stack_pop(s);
	free(s->first);
	free(s);
}