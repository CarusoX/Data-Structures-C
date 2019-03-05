#ifndef T_H
#define T_H

#include "data.h"

struct T {
    
    // Type of value
    type iType;
    
    // Union of possible values //
    data value;

    // Functions pointers //

    /* Set type */
    void (*set_type)(typeT, int);
    /* Set value */
    void (*set_value)(typeT, void*);
    /* Copy a struct */
    typeT (*copy)(typeT);
    /* Less than */
    int (*less_than)(typeT, typeT);
    /* Greater than */
    int (*greater_than)(typeT, typeT);
    /* Equals */
    int (*equals)(typeT, typeT);
    /* Destroy struct */
    void (*destroy)(typeT);
};

typeT T_init(int, void*);

void T_set_type(typeT, int);

void T_set_value(typeT, void*);

typeT T_copy(typeT);

int T_less_than(typeT, typeT);

int T_greater_than(typeT, typeT);

int T_equals(typeT, typeT);

void T_destroy(typeT);

#endif