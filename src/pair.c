#include "assert.h"
#include "pair.h"

pair pair_init(int t1, int t2, void* v1, void* v2) {

	pair p = (pair)malloc(sizeof(struct Pair));

	p->first = T_init(t1, v1);
	p->second = T_init(t2, v2);
	
	// Allocate functions
	p->set = pair_set;
	p->set_first = pair_set_first;
	p->set_second = pair_set_second;
	p->get_first = pair_get_first;
	p->get_second = pair_get_second;
	p->destroy = pair_destroy;

	return p;
}

void pair_set(pair p, void* v1, void* v2) {
	assert(p != NULL);
	pair_set_first(p, v1);
	pair_set_second(p, v2);
}

void pair_set_first(pair p, void* value) {
	assert(p != NULL);
	T_set_value(p->first, value);
}

void pair_set_second(pair p, void* value) {
	assert(p != NULL);
	T_set_value(p->second, value);
}

typeT pair_get_first(pair p) {
	assert(p != NULL);
	return p->first;
}

typeT pair_get_second(pair p){
	assert(p != NULL);
	return p->second;
}

void pair_destroy(pair p) {
	destroy(p->first);
	destroy(p->second);
	free(p); p = NULL;
}