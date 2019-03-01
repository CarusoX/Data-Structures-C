#include "stdlib.h"
#include "stdio.h"
#include "assert.h"
#include "T.h"

typedef struct vector {
    // Data //

    /* Data type */
    int type;
    /* Array of struct T */
    struct T* array;
    /* Number of elements stored */
    size_t sz;
    /* Total capacity */
    size_t capacity;
    /* Auto reference */
    struct vector* this;

    // Functions //

    /* Add element */
    void (*push_back)(struct vector*, void*);
    /* Remove element */
    void (*pop_back)(struct vector*);
    /* Get element at index i */
    struct T* (*at)(struct vector*, int);
    /* Clear vector */
    void (*clear)(struct vector*);
    /* Get size */
    size_t (*size)(struct vector*);
    /* Get capacity */
    size_t (*cap)(struct vector*);
} vector;

typedef struct vector* pvector;

void vector_init(pvector, int, size_t);

void vector_push_back(pvector, void*);

void vector_pop_back(pvector);

struct T* vector_at(pvector, int);

void vector_clear(pvector);

size_t vector_size(pvector);

size_t vector_cap(pvector);
