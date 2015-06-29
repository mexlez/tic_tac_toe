CC=gcc
CFLAGS=-I.
DEPS = tic_tac_toe.h
OBJ = tic_tac_toe.c

all: tic_tac_toe

tic_tac_toe: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
clean:
	rm tic_tac_toe
