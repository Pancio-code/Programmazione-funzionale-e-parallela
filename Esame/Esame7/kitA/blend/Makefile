CC     = gcc
CFLAGS = -O1 -Wall -g
LFLAGS = -msse4.2

blend: main.o blend.o pgm.o
	$(CC) $(CFLAGS) main.o blend.o pgm.o -o blend $(LFLAGS)

main.o: main.c blend.h
	$(CC) $(CFLAGS) main.c -c

pgm.o: pgm.c pgm.h
	$(CC) $(CFLAGS) pgm.c -c

blend.o: blend.c blend.h
	$(CC) $(CFLAGS) blend.c -c $(LFLAGS)

test:
	./blend sea.pgm pantheon.pgm blend.pgm

.phony: clean

clean:
	rm -f *.o blend blend.pgm
