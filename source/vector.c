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
    return v;
}

void vector_push_back(vector v, void* elem) {
    if(v->sz == v->capacity) {
        v->capacity *= 2;
        v->array = (struct T**)realloc(v->array, v->capacity * sizeof(typeT));
    }

    // Create struct T
    typeT t = T_init(v->type, elem);

    // Assign struct T
    v->array[v->sz] = t;

    v->sz++;
}

void vector_pop_back(vector v) {
    assert(0 < v->sz);
    v->sz--;
    free(v->array[v->sz]);
}

typeT vector_at(vector v, int p) {
    assert(0 <= p && p < (int)v->sz);
    return v->array[p];
}

void vector_push_at(vector v, typeT val, int p){
    assert(0 <= p && p < (int)v->sz);
    v->array[p] = val;
}

void vector_clear(vector v) {
    fore(i, 0, v->sz) free(v->array[i]);
    free(v->array);
    free(v);
}

size_t vector_size(vector v) {
    return v->sz;
}

