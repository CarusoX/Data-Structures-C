IDIR := include
SDIR := src
ODIR := obj
TDIR := test
BDIR := bin

CC := gcc
CFLAGS := -g -I$(IDIR) -std=c99
VPATH = $(SDIR):$(TDIR)

# Headers
_LIB = data.h defs.h pair.h rbtree.h set.h stack.h T.h vector.h
LIB = $(patsubst %, $(IDIR)/%, $(_LIB))

# Objects
_OBJ = pair.o rbtree.o set.o stack.o T.o vector.o
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))

# Tests
_TEST = pair_test.o set_test.o stack.o vector_test.o
TEST = $(patsubst %, $(ODIR)/%, $(_TEST))

$(ODIR)/%.o: %.c $(LIB)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BDIR)/%: $(OBJ) $(ODIR)/%.o
	$(CC) -o $@ $^ $(CFLAGS)

vector_test: $(BDIR)/vector_test
	$(BDIR)/vector_test

set_test: $(BDIR)/set_test
	$(BDIR)/set_test

pair_test: $(BDIR)/pair_test
	$(BDIR)/pair_test

stack_test: $(BDIR)/stack_test
	$(BDIR)/stack_test

%.valgrind: $(BDIR)/%
	valgrind --show-reachable=yes --leak-check=full $(BDIR)/$(subst .valgrind,,$@)

.PRECIOUS: $(ODIR)/%.o

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(BDIR)/*

