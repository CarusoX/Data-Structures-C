#include "pair.h"

// Init the pair with the types, but not the data //
pair pair_init(void* v1, void* v2, int t1, int t2){

	pair p = (pair)malloc(sizeof(struct Pair));

	p->first = T_init(t1, v1);
	p->second = T_init(t2, v2);
	
	// Allocate functions
	p->set_first = pair_set_first;
	p->get_first = pair_get_first;
	p->get_first_type = pair_get_first_type;
	p->set_second = pair_set_second;
	p->get_second = pair_get_second;
	p->get_second_type = pair_get_second_type;

	return p;
}

// Set the two elements in a given pair //
void pair_set(pair p, void* v1, void* v2){
	assert(p != NULL);
	pair_set_first(p, v1);
	pair_set_second(p, v2);
}

// Sets the first element of a pair //
void pair_set_first(pair p, void* value){
	assert(p != NULL);
	p -> first = T_init(T_get_type(p->first), value);
	T_set_value(p->first, value);
}

// Returns the first element in the pair //
data pair_get_first(pair p){
	assert(p != NULL);
	return T_get_value(p->first);
}

// Returns the type of the first element in the pair //
int pair_get_first_type(pair p){
	assert(p != NULL);
	return T_get_type(p->first);
}

// Sets the second element of a pair //
void pair_set_second(pair p, void* value){
	assert(p != NULL);
	p -> second = T_init(T_get_type(p->second), value);
	T_set_value(p->second, value);
}

// Returns the second element in the pair //
data pair_get_second(pair p){
	assert(p != NULL);
	return T_get_value(p->second);
}

// Returns the type of the second element in the pair //
int pair_get_second_type(pair p){
	assert(p != NULL);
	return T_get_type(p->first);
}

// Frees the memory of the pair //
void pair_destroy (pair p){
	free(p->first);
	free(p->second);
	free(p);
}