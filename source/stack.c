#include "stack.h"
#define fore(i, s, e) for(int i = s; i < e; i++)
#define typename(x) _Generic((x),				 \
                                                 \
unsigned char: 1,          						 \
  signed char: 2,					   char: 3,  \
    short int: 4,		 unsigned short int: 5,  \
          int: 6,			   unsigned int: 7,  \
     long int: 8,		  unsigned long int: 9,  \
long long int: 10, 	 unsigned long long int: 11, \
        float: 12,                   double: 13, \
  long double: 14,     	              int *: 15, \
       char *: 16,					 void *: 17, \
      default: 0)

p_stack stack_init(){
	p_stack s = (p_stack)malloc(sizeof(struct stack));
	s -> the_stack = NULL;
	s -> sz = 0;
}

void stack_push(p_stack s, void* elem){
	assert(s != NULL);
	p_node n = (p_node)malloc(sizeof(struct node));
	typeT t = T_init();
	T_set_type(t, typename(elem));
	T_set_value(t, elem);
	n -> t_node = t;
	n -> next = NULL;
	(s -> sz)++;
}

void stack_pop(p_stack s){
	assert(s != NULL);
	p_node n = s -> the_stack;
	s -> the_stack = n -> next;
	n -> next = NULL;
	free(n);
	(s -> sz)--;
}

data stack_top(p_stack s){
	assert(s != NULL);
	return T_get_value((s -> the_stack) -> t_node);
}

size_t stack_size(p_stack s){
	assert(s != NULL);
	return s -> sz;
}

bool stack_empty(p_stack s){
	return (s->sz == 0);
}

void stack_clear(p_stack s){
	fore(i, 0, s->sz) stack_pop(s);
    free(s);
}