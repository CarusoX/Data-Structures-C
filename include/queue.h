#ifndef QUEUE_H
#define QUEUE_H

#include "T.h"

typedef struct Queue {
    size_t sz;
	int type;
    list first;

	// Allocate functions

	/* Adds an element to the queue */
	void(*enqueue)(queue, typeT);
	/* Removes the last element in the queue */
	void(*dequeue)(queue);
	/* Insert an element in a desired position */
	void(*queue_insert)(queue q, typeT elem, int pos);
	/* Returns the first element in the queue */
	typeT(*qfirst)(queue);
}a;

queue queue_init(int type);

void queue_enqueue(queue q, typeT elem);

void queue_dequeue(queue q);

void queue_insert(queue q, typeT elem, int pos);

typeT queue_first(queue q);

void queue_clear(queue q);

void queue_destroy(queue q);

#endif