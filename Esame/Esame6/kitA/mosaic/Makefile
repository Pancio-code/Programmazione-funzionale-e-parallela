CC     = gcc
CFLAGS = -O1 -Wall
LFLAGS = -l OpenCL

mosaic: main.o clut.o pgm.o mosaic.o rand_perm.o
	$(CC) $(CFLAGS) main.o clut.o pgm.o mosaic.o rand_perm.o \
        -o mosaic $(LFLAGS)

main.o: main.c clut.h mosaic.h pgm.h
	$(CC) $(CFLAGS) main.c -c

mosaic.o: mosaic.c mosaic.h clut.h
	$(CC) $(CFLAGS) mosaic.c -c

clut.o: clut.c clut.h
	$(CC) $(CFLAGS) clut.c -c

pgm.o: pgm.c pgm.h
	$(CC) $(CFLAGS) pgm.c -c

rand_perm.o: rand_perm.c rand_perm.h
	$(CC) $(CFLAGS) rand_perm.c -c

test:
	./mosaic sheldon.pgm sheldon-mosaic.pgm 78

.phony: clean

clean:
	rm -f *.o mosaic colosseo-mosaic.pgm
