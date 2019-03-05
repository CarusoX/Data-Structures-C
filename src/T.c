#include "T.h"

typeT T_init(int iType, void* value) {
    typeT t = (typeT)malloc(sizeof(struct T));

    t->set_type = T_set_type;
    t->set_value = T_set_value;
    t->copy = T_copy;
    t->less_than = T_less_than;
    t->greater_than = T_greater_than;
    t->equals = T_equals;
    t->destroy = T_destroy;

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
        case UChar:
            t->value.uc = *(unsigned char*)value;
            break;
        case SChar:
            t->value.sc = *(signed char*)value;
            break;
        case Char:
            t->value.c = *(char*)value;
            break;
        case SInt:
            t->value.si = *(short int*)value;
            break;
        case USInt:
            t->value.usi = *(unsigned short int*)value;
            break;
        case Int:
            t->value.i = *(int*)value;
            break;
        case UInt:
            t->value.ui = *(unsigned int*)value;
            break;
        case LInt:
            t->value.li = *(long int*)value;
            break;
        case ULInt:
            t->value.uli = *(unsigned long int*)value;
            break;
        case LLInt:
            t->value.lli = *(long long int*)value;
            break;
        case ULLInt:
            t->value.ulli = *(unsigned long long int*)value;
            break;
        case Float:
            t->value.f = *(float*)value;
            break;
        case Double:
            t->value.d = *(double*)value;
            break;
        case Pair:
            t->value.p = *(pair*)value;
            break;
        case Vector:
            t->value.v = *(vector*)value;
            break;
        case Set:
            t->value.s = *(set*)value;
            break;
        case P_Int:
            t->value.p_i = (int*)value;
            break;
        case P_Char:
            t->value.p_c = (char*)value;
            break;
        case P_Void:
            t->value.p_v = (void*)value;
            break;
        default:
            assert(0);
    };
}

typeT T_copy(typeT a) {
    assert(a != NULL);
    typeT t = (typeT)malloc(sizeof(struct T));
    t->iType = a->iType;
    t->value = a->value;

    t->set_type = T_set_type;
    t->set_value = T_set_value;
    t->copy = T_copy;
    t->less_than = T_less_than;
    t->greater_than = T_greater_than;
    t->equals = T_equals;
    t->destroy = T_destroy;
}

int T_less_than(typeT a, typeT b) {

    assert(a->iType != 0);
    assert(a->iType == b->iType);

    switch(a->iType) {
        case UChar:
            return a->value.uc < b->value.uc;
        case SChar:
            return a->value.sc < b->value.sc;
        case Char:
            return a->value.c < b->value.c;
        case SInt:
            return a->value.si < b->value.si;
        case USInt:
            return a->value.usi < b->value.usi;
        case Int:
            return a->value.i < b->value.i;
        case UInt:
            return a->value.ui < b->value.ui;
        case LInt:
            return b->value.li < a->value.li;
        case ULInt:
            return b->value.uli < a->value.uli;
        case LLInt:
            return b->value.lli < a->value.lli;
        case ULLInt:
            return b->value.ulli < a->value.ulli;
        case Float:
            return a->value.f + 0.00001 < b->value.f;
        case Double:
            return a->value.d + 0.0000001 < b->value.d;
        case Pair:
            if(!equals(get_first(a->value.p), get_first(b->value.p))) {
                return less_than(get_first(a->value.p), get_first(b->value.p));
            } else {
                return less_than(get_second(a->value.p), get_second(b->value.p));
            }
        case P_Int:
            return *(a->value.p_i) > *(b->value.p_i);
        case P_Char:
            return *(a->value.p_c) > *(b->value.p_c);
        default:
            return 0;
    };
}

int T_greater_than(typeT a, typeT b) {

    assert(a->iType != 0);
    assert(a->iType == b->iType);

    switch(a->iType) {
        case UChar:
            return a->value.uc > b->value.uc;
        case SChar:
            return a->value.sc > b->value.sc;
        case Char:
            return a->value.c > b->value.c;
        case SInt:
            return a->value.si > b->value.si;
        case USInt:
            return a->value.usi > b->value.usi;
        case Int:
            return a->value.i > b->value.i;
        case UInt:
            return a->value.ui > b->value.ui;
        case LInt:
            return b->value.li > a->value.li;
        case ULInt:
            return b->value.uli > a->value.uli;
        case LLInt:
            return b->value.lli > a->value.lli;
        case ULLInt:
            return b->value.ulli > a->value.ulli;
        case Float:
            return a->value.f > b->value.f + 0.00001;
        case Double:
            return a->value.d > b->value.d + 0.0000001;
        case Pair:
            if(!equals(get_first(a->value.p), get_first(b->value.p))) {
                return greater_than(get_first(a->value.p), get_first(b->value.p));
            } else {
                return greater_than(get_second(a->value.p), get_second(b->value.p));
            }
        case P_Int:
            return *(a->value.p_i) > *(b->value.p_i);
        case P_Char:
            return *(a->value.p_c) > *(b->value.p_c);
        default:
            return 0;
    };
}

int T_equals(typeT a, typeT b) {
    assert(a->iType != 0);
    assert(a->iType == b->iType);

    switch(a->iType) {
        case UChar:
            return a->value.uc == b->value.uc;
        case SChar:
            return a->value.sc == b->value.sc;
        case Char:
            return a->value.c == b->value.c;
        case SInt:
            return a->value.si == b->value.si;
        case USInt:
            return a->value.usi == b->value.usi;
        case Int:
            return a->value.i == b->value.i;
        case UInt:
            return a->value.ui == b->value.ui;
        case LInt:
            return b->value.li == a->value.li;
        case ULInt:
            return b->value.uli == a->value.uli;
        case LLInt:
            return b->value.lli == a->value.lli;
        case ULLInt:
            return b->value.ulli == a->value.ulli;
        case Float:
            return abs(a->value.f - b->value.f) < 0.00001;
        case Double:
            return abs(a->value.d - b->value.d) < 0.0000001;
        case Pair:
            return (equals(a->value.p->first, b->value.p->first)
                 && equals(a->value.p->second, b->value.p->second));
        case P_Int:
            return *(a->value.p_i) == *(b->value.p_i);
        case P_Char:
            return *(a->value.p_c) == *(b->value.p_c);
        default:
            return 0;
    };
}

void T_destroy(typeT t) {
    switch (t->iType) {
        case Pair:
            destroy(t->value.p);
            break;
        case Vector:
            destroy(t->value.v);
            break;
        case Set:
            destroy(t->value.s);
            break;
    };
    free(t); t = NULL;
}