CC     = gcc
CFLAGS = -O2 -Wall -Wno-deprecated-declarations
LFLAGS = -l OpenCL

poster: main.o clut.o pgm.o art.o
	$(CC) $(CFLAGS) main.o clut.o pgm.o art.o \
        -o art $(LFLAGS)

main.o: main.c clut.h art.h pgm.h
	$(CC) $(CFLAGS) main.c -c

art.o: art.c art.h clut.h
	$(CC) $(CFLAGS) art.c -c

clut.o: clut.c clut.h
	$(CC) $(CFLAGS) clut.c -c

pgm.o: pgm.c pgm.h
	$(CC) $(CFLAGS) pgm.c -c

test:
	./art colosseo.pgm colosseo-art.pgm

.phony: clean

clean:
	rm -f *.o art colosseo-art.pgm
