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
            t->value.uc = *(unsigned char*)value;
            break;
        case 2:
            t->value.sc = *(signed char*)value;
            break;
        case 3:
            t->value.c = *(char*)value;
            break;
        case 4:
            t->value.si = *(short int*)value;
            break;
        case 5:
            t->value.usi = *(unsigned short int*)value;
            break;
        case 6:
            t->value.i = *(int*)value;
            break;
        case 7:
            t->value.ui = *(unsigned int*)value;
            break;
        case 8:
            t->value.li = *(long int*)value;
            break;
        case 9:
            t->value.uli = *(unsigned long int*)value;
            break;
        case 10:
            t->value.lli = *(long long int*)value;
            break;
        case 11:
            t->value.ulli = *(unsigned long long int*)value;
            break;
        case 12:
            t->value.f = *(float*)value;
            break;
        case 13:
            t->value.d = *(double*)value;
            break;
        case 14:
            t->value.ld = *(long double*)value;
            break;
        case 15:
            t->value.p_i = (int*)value;
            break;
        case 16:
            t->value.p_c = (char*)value;
            break;
        case 17:
            t->value.p_v = (void*)value;
            break;
        default:
            printf("Unkown error on T_set_value\n");
            assert(0);
            exit(-1);
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