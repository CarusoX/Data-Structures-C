#include "assert.h"
#include "defs.h"
#include "stdlib.h"
#include "T.h"

typedef struct DYNAMIC_ARRAY* vector;

typedef struct DYNAMIC_ARRAY {
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
    /* Get element at index i */
    typeT (*at)(vector, int);
    /* Clear vector */
    void (*clear)(vector);
    /* Get size */
    size_t (*size)(vector);
} d_array;

vector vector_init(int, size_t);

void vector_push_back(vector, void*);

void vector_pop_back(vector);

typeT vector_at(vector, int);

void vector_clear(vector);

size_t vector_size(vector);