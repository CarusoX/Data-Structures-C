#include "T.h"

typeT T_init(int iType, void* value) {
    typeT t = (typeT)malloc(sizeof(struct T));

    t->set_type = T_set_type;
    t->set_value = T_set_value;
    t->get_type = T_get_type;
    t->get_value = T_get_value;
    t->less_than = T_less_than;
    t->greater_than = T_greater_than;
    t->equals = T_equals;

    T_set_type(t, iType);
    T_set_value(t, value);

    return t;
}

void T_set_type(typeT t, int type) {
    t->iType = type;
}

void T_set_value(typeT t, void* value) {
    assert(t->iType != 0);
    
    switch(t->iType) {
        case 1:
            t->value.i = *(int*)value;
            break;

        case 2:
            t->value.l = *(long long*)value;
            break;

        case 3:
            t->value.c = *(char*)value;
            break;
        default:
            assert(0);
            break;
    };
}

int T_get_type(typeT t) {
    return t->iType;
}

data T_get_value(typeT t) {
    return t->value;
}

int T_less_than(typeT a, typeT b) {
    return a->value.i < b->value.i;
}

int T_greater_than(typeT a, typeT b) {
    return a->value.i > b->value.i;
}

int T_equals(typeT a, typeT b) {
    return a->value.i == b->value.i;
}