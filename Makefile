IDIR := include
SDIR := src
ODIR := obj
TDIR := test
BDIR := bin

CC := gcc
CFLAGS := -g -I$(IDIR) -std=c99
VPATH = src:test

# Headers
_LIB = data.h defs.h
LIB = $(patsubst %, $(IDIR)/%, $(_LIB))

$(ODIR)/%.o: %.c $(LIB)
	$(CC) -c -o $@ $< $(CFLAGS)

bin/vector_test: $(ODIR)/vector_test.o $(ODIR)/T.o $(ODIR)/vector.o $(ODIR)/pair.o
	$(CC) -o $@ $^ $(CFLAGS)

vector_test: bin/vector_test
	bin/vector_test

bin/set_test: $(ODIR)/set_test.o $(ODIR)/T.o $(ODIR)/set.o $(ODIR)/rbtree.o 
	$(CC) -o $@ $^ $(CFLAGS)

set_test: bin/set_test
	bin/set_test

bin/pair_test: $(ODIR)/pair_test.o $(ODIR)/T.o $(ODIR)/pair.o
	$(CC) -o $@ $^ $(CFLAGS)

pair_test: bin/pair_test
	bin/pair_test

bin/stack_test: $(ODIR)/stack_test.o $(ODIR)/T.o $(ODIR)/stack.o
	$(CC) -o $@ $^ $(CFLAGS)

stack_test: bin/stack_test
	bin/stack_test

%.valgrind: bin/%
	valgrind --show-reachable=yes --leak-check=full ./bin/$(subst .valgrind,,$@)

.PRECIOUS: $(ODIR)/%.o

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(BDIR)/*

