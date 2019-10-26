#include "queue.h"

int main() {

	// Time Set
	clock_t begin = clock();

	// Variables //
	queue q, qq;
	pair p1, p2;
	int x, y;

	// Init the two queues //
	q = queue_init(Int);
	qq = queue_init(Pair);

	// Testing empty queue //
	
	dequeue(q);dequeue(q);dequeue(q);
	dequeue(q);dequeue(q);dequeue(q);

	dequeue(qq);dequeue(qq);dequeue(qq);
	dequeue(qq);dequeue(qq);dequeue(qq);

	// Testing push function //
	x = 1; enqueue(q, x);
	x = 2; enqueue(q, x);
	x = 3; enqueue(q, x);
	x = 4; enqueue(q, x);
	x = 5; enqueue(q, x);

	printf("%d", q->first_elem(q)->value.i); // 1
	dequeue(q);
	printf("%d", (int)q->first_elem(q)->value.i); // 2
	dequeue(q);
	printf("%d", (int)q->first_elem(q)->value.i); // 3
	dequeue(q);
	printf("%d", (int)q->first_elem(q)->value.i); // 4
	dequeue(q);
	printf("%d", (int)q->first_elem(q)->value.i); // 5
	dequeue(q);
	
	x = 123, y = 321; p1 = pair_init(Int, Int, &x, &y);
	x = 345, y = 543; p2 = pair_init(Int, Int, &x, &y);
	
	enqueue(qq, p1);
	enqueue(qq, p2);

	printf("%d", (int)qq->first_elem(qq)->value.i); // 123, 321
	dequeue(qq);
	printf("%d", (int)qq->first_elem(qq)->value.i); // 345, 543
	dequeue(qq);

	queue_destroy(q);
	queue_destroy(qq);

	clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%lf Seconds\n", time_spent);

	return 0;
}
