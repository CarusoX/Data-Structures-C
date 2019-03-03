CC = gcc
CFLAGS = -pedantic -std=c99 -g

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

vector_test: T.o vector.o vector_test.o
	$(CC) $(CFLAGS) -o $@ $^

set_test : T.o bst.o rbtree.o set_test.o
	$(CC) $(CFLAGS) -o $@ $^

run_vector_test: vector_test
	./vector_test

run_vector_test_valgrind: vector_test
	valgrind --show-reachable=yes --leak-check=full ./vector_test

run_set_test: set_test
	./set_test

run_set_test_valgrind: set_test
	valgrind --show-reachable=yes --leak-check=full ./set_test

clean:
	rm -f vector_test set_test *.o