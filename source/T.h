#include "assert.h"
#include "defs.h"
#include "stdlib.h"
#include "stdio.h"

//Possible values of the pair
typedef union Data {
	unsigned char uc;               //  1
	signed char sc;                 //  2
	char c;                         //  3
	short int si;                   //  4
	unsigned short int usi;         //  5
	int i;                          //  6
	unsigned int ui;                //  7
	long int li;                    //  8
	unsigned long int uli;          //  9
	long long int lli;              // 10
	unsigned long long int ulli;    // 11
	float f;                        // 12
	double d;                       // 13
	long double ld;                 // 14
    //pair p;
    //stack s;
	int* p_i;                       // 15
	char* p_c;                      // 16
	void* p_v;                      // 17
} data;

// Data type //
enum type {
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
    //Pair,
    //Stack,
    P_Int,
    P_Char,
    P_Void,
} iType;

typedef struct T* typeT;

struct T {
    
    enum types iType;
    
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

