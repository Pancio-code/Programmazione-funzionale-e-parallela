CC=gcc
FLAGS=-O1 -Wall -msse4.2

sumeven: sumeven.h sumeven.c sumeven_sse.c main.c
	$(CC) $(FLAGS) sumeven.c sumeven_sse.c main.c -o sumeven

.phony: clean

clean:
	rm -f sumeven
