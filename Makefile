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

bin/vector: $(ODIR)/vector_test.o $(ODIR)/T.o $(ODIR)/vector.o
	$(CC) -o $@ $^ $(CFLAGS)

vector_test: bin/vector
	bin/vector

bin/set: $(ODIR)/set_test.o $(ODIR)/T.o $(ODIR)/set.o $(ODIR)/rbtree.o 
	$(CC) -o $@ $^ $(CFLAGS)

set_test: bin/set
	./bin/set

.PRECIOUS: $(ODIR)/%.o

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(BDIR)/*

