CC     = gcc
CFLAGS = -O2 -Wall
LFLAGS = -l OpenCL

mix: main.o clut.o pgm.o mix.o
	$(CC) $(CFLAGS) main.o clut.o pgm.o mix.o \
        -o mix $(LFLAGS)

main.o: main.c clut.h mix.h pgm.h
	$(CC) $(CFLAGS) main.c -c

mix.o: mix.c mix.h clut.h
	$(CC) $(CFLAGS) mix.c -c

clut.o: clut.c clut.h
	$(CC) $(CFLAGS) clut.c -c

pgm.o: pgm.c pgm.h
	$(CC) $(CFLAGS) pgm.c -c

test:
	./mix sea.pgm pantheon.pgm mix.pgm

.phony: clean

clean:
	rm -f *.o mix mix.pgm
