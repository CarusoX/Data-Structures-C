#include "queue.h"

queue queue_init(int type){
	queue q = (queue)malloc(sizeof(struct Queue));
	q->first = NULL;
	q->type = type;
	q->sz = 0;
	
	q->enqueue = queue_enqueue;
	q->dequeue = queue_dequeue;
	q->first = queue_first;

	return q;
}

void queue_enqueue(queue q, typeT elem){
	assert(q != NULL);
	list l = (list)malloc(sizeof(struct List));
	l->elem = elem;
	l->next = q->first;
	q->first = l;
	q->sz++;
}

void queue_dequeue(queue q){
	assert(q != NULL);
	list l = q->first;
	q->first = l->next;
	l->next = NULL;
	free(l); l = NULL;
	q->sz--;
}

void queue_insert(queue q, typeT elem, int pos){
	assert(pos > -1 && pos < q->sz && q != NULL);
	list new = (list)malloc(sizeof(struct List));
	list l = q->first->next; // elem l
	list pl = q->first; 	 // elem prev to l
	while(pos){
		l = l->next;
		pl = pl->next;
		pos--;
	}
	pl->next = new;
	new->next = l;
	new->elem = elem;
	q->sz++;
}

typeT queue_first(queue q){
	assert(q != NULL);
	return q->first->elem;
}

void queue_clear(queue q){
	assert(q != NULL);
	while(q->sz){
		queue_dequeue(q);
	}
}

void queue_destroy(queue q){
	queue_clear(q);
	free(q); q = NULL;
}