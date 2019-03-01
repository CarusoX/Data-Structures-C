CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99 -g

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

vector_test: T.o vector.o vector_test.o
	$(CC) $(CFLAGS) -o $@ $^

run_vector_test: vector_test
	./vector_test

run_vector_test_valgrind: vector_test
	valgrind --show-reachable=yes --leak-check=full  ./vector_test

clean:
	rm -f vector_test *.o