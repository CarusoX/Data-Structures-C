#ifndef DATA_H
#define DATA_H

typedef struct Pair* pair;
typedef struct Vector* vector;
typedef struct Set* set;

#include "pair.h"
#include "vector.h"
#include "set.h"

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
    pair p;                         // 14
    vector v;                       // 15
    set s;                          // 16
	int* p_i;                       // 17
	char* p_c;                      // 18
	void* p_v;                      // 19
} data;

typedef enum types {
    Undefined,                      //  0
    UChar,                          //  1
    SChar,                          //  2
    Char,                           //  3
    SInt,                           //  4
    USInt,                          //  5
    Int,                            //  6
    UInt,                           //  7
    LInt,                           //  8
    ULInt,                          //  9
    LLInt,                          // 10
    ULLInt,                         // 11
    Float,                          // 12
    Double,                         // 13
    Pair,                           // 14
    Vector,                         // 15
    Set,                            // 16
    P_Int,                          // 17
    P_Char,                         // 18
    P_Void,                         // 19
} type;

#endif