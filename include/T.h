#include "assert.h"
#include "defs.h"
#include "data.h"
#include "stdlib.h"

typedef struct T* typeT;

typedef struct T {
    
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
    /* Get value */
    data (*get_value)(typeT);
    /* Less than */
    int (*less_than)(typeT, typeT);
    /* Greater than */
    int (*greater_than)(typeT, typeT);
    /* Equals */
    int (*equals)(typeT, typeT);
} T;

typeT T_init();
void T_set_type(typeT, int);
void T_set_value(typeT, void*);
int T_get_type(typeT);
data T_get_value(typeT);
int T_less_than(typeT, typeT);
int T_greater_than(typeT, typeT);
int T_equals(typeT, typeT);

