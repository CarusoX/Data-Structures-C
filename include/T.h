#ifndef T_H
#define T_H

#include "assert.h"
#include "defs.h"
#include "data.h"
#include "stdlib.h"
#include "stdio.h"

typedef struct T* typeT;

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
    /* Get type */
    int (*get_type)(typeT);
    /* Less than */
    int (*less_than)(typeT, typeT);
    /* Greater than */
    int (*greater_than)(typeT, typeT);
    /* Equals */
    int (*equals)(typeT, typeT);
};

typeT T_init(int, void*);
void T_set_type(typeT, int);
void T_set_value(typeT, void*);
int T_get_type(typeT);
int T_less_than(typeT, typeT);
int T_greater_than(typeT, typeT);
int T_equals(typeT, typeT);

#endif