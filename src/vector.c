#include "vector.h"

vector vector_init(int type, size_t cap) {
    vector v = (vector)malloc(sizeof(d_array));

    // Grab data
    v->array = (typeT*)malloc(cap * sizeof(typeT));
    v->type = type;
    v->sz = 0;
    v->capacity = cap;

    // Allocate functions
    v->push_back = vector_push_back;
    v->pop_back = vector_pop_back;
    v->at = vector_at;
    v->clear = vector_clear;
    v->size = vector_size;
    v->destroy = vector_destroy;
    return v;
}

void vector_push_back(vector v, void* elem) {
    if(v->sz == v->capacity) {
        v->capacity *= 2;
        v->array = (typeT*)realloc(v->array, v->capacity * sizeof(typeT));
    }

    // Create struct T
    typeT t = T_init(v->type, elem);

    // Assign struct T
    v->array[v->sz] = t;

    v->sz++;
}

void vector_pop_back(vector v) {
    assert(0 < v->sz);

    // Clear last element
    destroy(v->array[--v->sz]);
}

void vector_set_at(vector v, void* elem, int p){
    assert(0 <= p && p < (int)v->sz);

    // Create struct T
    typeT t = T_init(v->type, elem);

    // Clear current position
    destroy(v->array[p]);

    // Assign new struct T
    v->array[p] = t;
}

typeT vector_at(vector v, int p) {
    assert(0 <= p && p < (int)v->sz);
    return v->array[p];
}

size_t vector_size(vector v) {
    return v->sz;
}

void vector_clear(vector v) {
    // Clear what we stored
    fore(i, 0, v->sz) destroy(v->array[i]);
    v->sz = 0;
}

void vector_destroy(vector v) {
    clear(v);
    // Free vector
    free(v->array); v->array = NULL;
    free(v); v = NULL;
}

