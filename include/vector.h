#ifndef VECTOR_H
#define VECTOR_H

typedef struct T* typeT;

#include "defs.h"
#include "stdlib.h"
#include "T.h"

typedef struct Vector* vector;

typedef struct Vector {
    // Data //

    /* Array of struct T */
    typeT* array;
    /* Data type */
    int type;
    /* Number of elements stored */
    size_t sz;
    /* Total capacity */
    size_t capacity;

    // Functions //

    /* Add element */
    void (*push_back)(vector, void*);
    /* Remove element */
    void (*pop_back)(vector);
    /* Set value of element at index i */
    void (*set_at)(vector, typeT, int);
    /* Get element at index i */
    typeT (*at)(vector, int);
    /* Get size */
    size_t (*size)(vector);
    /* Clear vector */
    void (*clear)(vector);
    /* Destroy vector */
    void (*destroy)(vector);
} d_array;

vector vector_init(int, size_t);

void vector_push_back(vector, void*);

void vector_pop_back(vector);

void vector_set_at(vector, void*, int);

typeT vector_at(vector, int);

size_t vector_size(vector);

void vector_clear(vector);

void vector_destroy(vector);
#endif
