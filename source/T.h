#include "assert.h"
#include "defs.h"
#include "stdlib.h"

// typedef union Data { 0 undefined
//     int i;           1
//     long long l;     2
//     char c;          3
// } data;

//Possible values of the pair
typedef union Data {
	unsigned char uc;
	signed char sc;
	char c;
	short int si;
	unsigned short int usi;
	int i;
	unsigned int ui;
	long int li;
	unsigned long int uli;
	long long int lli;
	unsigned long long int ulli;
	float f;
	double d;
	long double ld;
	int* p_i;
	char* p_c;
	void* p_v;
} data;


typedef struct T* typeT;

struct T {
    // Data type //
    enum types {
        Undefined,
        UChar,
        SChar,
        Char,
        SInt,
        USInt,
        Int,
        UInt,
        LInt,
        ULInt,
        LLInt,
        ULLInt,
        Float,
        Double,
        LDouble,
        P_Int,
        P_Char,
        P_Void,
    } iType;
    
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
};

typeT T_init();
void T_set_type(typeT, int);
void T_set_value(typeT, void*);
int T_get_type(typeT);
data T_get_value(typeT);
int T_less_than(typeT, typeT);
int T_greater_than(typeT, typeT);
int T_equals(typeT, typeT);

