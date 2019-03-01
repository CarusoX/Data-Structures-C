#include "stdlib.h"
#include "stdio.h"
#include "assert.h"

typedef union Data {
    int i;
    long long l;
    char c;
} data;

struct T {
    // Data type //
    enum types {
        Undefined,
        Int,
        LongLong,
        Char,
    } iType;
    
    // Union of possible values //
    data value;

    // Functions pointers //

    /* Set type */
    void (*set_type)(struct T*, int);
    /* Set value */
    void (*set_value)(struct T*, void*);
    /* Get type */
    int (*get_type)(struct T*);
    /* Get value */
    data (*get_value)(struct T*);
};

void T_init(struct T*);
void T_set_type(struct T*, int);
void T_set_value(struct T*, void*);
int T_get_type(struct T*);
data T_get_value(struct T*);

