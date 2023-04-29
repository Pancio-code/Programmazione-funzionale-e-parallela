CC     = gcc
CFLAGS = -O2 -Wall
LFLAGS = -l OpenCL

scale2x: main.o clut.o pgm.o scale2x.o
	$(CC) $(CFLAGS) main.o clut.o pgm.o scale2x.o \
        -o scale2x $(LFLAGS)

main.o: main.c clut.h scale2x.h pgm.h
	$(CC) $(CFLAGS) main.c -c

scale2x.o: scale2x.c scale2x.h clut.h
	$(CC) $(CFLAGS) scale2x.c -c

clut.o: clut.c clut.h
	$(CC) $(CFLAGS) clut.c -c

pgm.o: pgm.c pgm.h
	$(CC) $(CFLAGS) pgm.c -c

test:
	./scale2x colosseo.pgm colosseo-scale2x.pgm

.phony: clean

clean:
	rm -f *.o scale2x colosseo-scale2x.pgm
