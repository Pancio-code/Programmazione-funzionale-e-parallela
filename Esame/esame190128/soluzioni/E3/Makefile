CC=gcc
FLAGS=-O1 -Wall -msse4.2

minmax: minmax.h minmax.c minmax_sse.c main.c
	$(CC) $(FLAGS) minmax.c minmax_sse.c main.c -o minmax

.phony: clean

clean:
	rm -f minmax
