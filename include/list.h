#ifndef LIST_H
#define LIST_H

#include "T.h"

// Struct containing the data of only one node //
struct List {
	/* The data of the node */
	typeT elem;
	/* Pointer to next element */
	list next;
};

#endif