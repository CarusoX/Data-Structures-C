#include "T.h"

void T_init(struct T* t) {
    t->set_type = T_set_type;
    t->set_value = T_set_value;
    t->get_type = T_get_type;
    t->get_value = T_get_value;
}

void T_set_type(struct T* t, int type) {
    t->iType = type;
}

void T_set_value(struct T* t, void* value) {
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
            printf("Unkown error on T_set_value\n");
            exit(-1);
            break;
    };
}

int T_get_type(struct T* t) {
    return t->iType;
}

data T_get_value(struct T* t) {
    return t->value;
}