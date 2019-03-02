#include "pair.h"

pair init_pair(){
	pair p = (pair)malloc(sizeof(struct Pair));
	p->first = NULL;
	p->second = NULL;
	return p;
}

void set_pair(pair p, void* v1, void* v2, int t1, int t2){
	set_first(p, v1, t1);
	set_second(p, v2, t2);
}

void set_first(pair p, void* value, int type){
	p -> first = T_init(type, value);
	T_set_type(p->first, type);
	T_set_value(p->first, value);
}

data get_first(pair p){
	return T_get_value(p->first);
}

int get_first_type(pair p){
	return T_get_type(p->first);
}

void set_second(pair p, void* value, int type){
	p -> second = T_init(type, value);
	T_set_type(p->second, type);
	T_set_value(p->second, value);
}

data get_second(pair p){
	return T_get_value(p->second);
}

int get_second_type(pair p){
	return T_get_type(p->first);
}

void destroy_pair (pair p){
	free(p);
}