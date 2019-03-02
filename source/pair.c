#include "pair.h"

pair pair_init(){
	pair p = (pair)malloc(sizeof(struct Pair));
	p->first = NULL;
	p->second = NULL;
	return p;
}

void pair_set(pair p, void* v1, void* v2, int t1, int t2){
	pair_set_first(p, v1, t1);
	pair_set_second(p, v2, t2);
}

void pair_set_first(pair p, void* value, int type){
	p -> first = T_init(type, value);
	T_set_type(p->first, type);
	T_set_value(p->first, value);
}

data pair_get_first(pair p){
	return T_get_value(p->first);
}

int pair_get_first_type(pair p){
	return T_get_type(p->first);
}

void pair_set_second(pair p, void* value, int type){
	p -> second = T_init(type, value);
	T_set_type(p->second, type);
	T_set_value(p->second, value);
}

data pair_get_second(pair p){
	return T_get_value(p->second);
}

int pair_get_second_type(pair p){
	return T_get_type(p->first);
}

void destroy_pair (pair p){
	free(p);
}