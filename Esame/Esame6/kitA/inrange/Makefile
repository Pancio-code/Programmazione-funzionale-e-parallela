CC     = gcc
CFLAGS = -O1 -Wall -g
LFLAGS = -msse4.2

inrange: main.o inrange.o
	$(CC) $(CFLAGS) main.o inrange.o -o inrange $(LFLAGS)

main.o: main.c inrange.h
	$(CC) $(CFLAGS) main.c -c

inrange.o: inrange.c inrange.h
	$(CC) $(CFLAGS) inrange.c -c $(LFLAGS)

.phony: clean

clean:
	rm -f *.o inrange inrange.pgm
