#include "pair.h"

/*
The syntax is similar to a simple switch statement
for types:_Generic( 'a', char: 1, int: 2, long: 3, default: 0)
returns 2 (character constants are ints in C).
*/

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

p_pair init_pair(){
	p_pair p = (p_pair)malloc(sizeof(struct pair));
	p->first = NULL;
	p->second = NULL;
	return p;
}

void set_first(p_pair p, void* value){
	T_init(typename(value), value);
	T_set_type(p->first, typename(value));
	T_set_value(p->first, value);
}

data get_first(p_pair p){
	return T_get_value(p->first);
}

void set_second(p_pair p, void* value){
	T_init(typename(value), value);
	T_set_type(p->second, typename(value));
	T_set_value(p->second, value);
}

data get_second(p_pair p){
	return T_get_value(p->second);
}
