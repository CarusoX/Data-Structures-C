#include "vector.h"

#define fore(i, s, e) for(int i = s; i < e; i++)

void vector_init(pvector v, int type, size_t cap) {
    assert(0 < cap);

    // Grab data
    v->type = type;
    v->array = (struct T*)malloc(cap * sizeof(struct T));
    v->sz = 0;
    v->capacity = cap;
    v->this = v;

    // Allocate functions
    v->push_back = vector_push_back;
    v->pop_back = vector_pop_back;
    v->at = vector_at;
    v->clear = vector_clear;
    v->size = vector_size;
    v->cap = vector_cap;
}

void vector_push_back(pvector v, void* elem) {
    if(v->sz == v->capacity) {
        v->capacity *= 2;
        v->array = (struct T*)realloc(v->array, v->capacity * sizeof(struct T));
    }

    struct T* t = &v->array[v->sz];

    // Bind functions
    T_init(t);
    (*t).set_type(t, v->type);
    (*t).set_value(t, elem);
    v->sz++;
}

void vector_pop_back(pvector v) {
    assert(0 < v->sz);
    v->sz--;
}

struct T* vector_at(pvector v, int p) {
    assert(0 <= p && p < (int)v->sz);
    return v->array + p;
}

void vector_clear(pvector v) {
    free(v->array);
    v->array = NULL;
    v->sz = v->capacity = 0;
}

size_t vector_size(pvector v) {
    return v->sz;
}

size_t vector_cap(pvector v) {
    return v->capacity;
}

