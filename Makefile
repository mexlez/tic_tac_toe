CC=gcc
CFLAGS=-I.
DEPS = tic_tac_toe.h
OBJ = tic_tac_toe.c

$.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
tic_tac_toe: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

