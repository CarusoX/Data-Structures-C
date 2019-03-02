#include "stack.h"
#define fore(i, s, e) for(int i = s; i < e; i++)

stack stack_init(){
	stack s = (stack)malloc(sizeof(struct Stack));
	s -> the_S= NULL;
	s -> sz = 0;
}

void stack_push(stack s, void* elem, int type){
	assert(s != NULL);
	node n = (node)malloc(sizeof(struct Node));
	typeT t = T_init();
	T_set_type(t, type);
	T_set_value(t, elem);
	n -> t_node = t;
	n -> next = NULL;
	(s -> sz)++;
}

void stack_pop(stack s){
	assert(s != NULL);
	node n = s -> the_stack;
	s -> the_stack = n -> next;
	n -> next = NULL;
	free(n);
	(s -> sz)--;
}

data stack_top(stack s){
	assert(s != NULL);
	return T_get_value((s -> the_stack) -> t_node);
}

int stack_top_type(stack s){
	assert(s != NULL);
	return T_get_type(s->the_stack->t_node);
}

size_t stack_size(stack s){
	assert(s != NULL);
	return s -> sz;
}

bool stack_empty(stack s){
	return (s->sz == 0);
}

void stack_clear(stack s){
	fore(i, 0, s->sz) stack_pop(s);
    free(s);
}