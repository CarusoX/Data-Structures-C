#include "vector.h"

#define fore(i, s, e) for(int i = s; i < e; i++)

vector vector_init(int type, size_t cap) {
    assert(0 < cap);

    vector v = (vector)malloc(sizeof(struct DYNAMIC_ARRAY));

    // Grab data
    v->array = (struct T**)malloc(cap * sizeof(typeT));
    v->type = type;
    v->sz = 0;
    v->capacity = cap;

    // Allocate functions
    v->push_back = vector_push_back;
    v->pop_back = vector_pop_back;
    v->at = vector_at;
    v->clear = vector_clear;
    v->size = vector_size;
    v->cap = vector_cap;
    return v;
}

void vector_push_back(vector v, void* elem) {
    if(v->sz == v->capacity) {
        v->capacity *= 2;
        v->array = (struct T**)realloc(v->array, v->capacity * sizeof(typeT));
    }

    // Create struct T
    typeT t = T_init();
    t->set_type(t, v->type);
    t->set_value(t, elem);

    // Assign struct T
    v->array[v->sz] = t;

    v->sz++;
}

void vector_pop_back(vector v) {
    assert(0 < v->sz);
    v->sz--;
}

typeT vector_at(vector v, int p) {
    assert(0 <= p && p < (int)v->sz);
    return v->array[p];
}

void vector_clear(vector v) {
    free(v->array);
    v->array = NULL;
    v->sz = v->capacity = 0;
}

size_t vector_size(vector v) {
    return v->sz;
}

