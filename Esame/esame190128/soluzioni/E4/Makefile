CC     = gcc
CFLAGS = -O1 -Wall

ifeq ($(shell uname -s),Linux)
		LFLAGS = -lOpenCL
endif

ifeq ($(shell uname -s),Darwin)
		LFLAGS = -framework OpenCL
endif

bw: main.o clut.o pgm.o bw.o
	$(CC) $(CFLAGS) main.o clut.o pgm.o bw.o \
        -o bw $(LFLAGS)

main.o: main.c clut.h bw.h pgm.h
	$(CC) $(CFLAGS) main.c -c

bw.o: bw.c bw.h clut.h
	$(CC) $(CFLAGS) bw.c -c

clut.o: clut.c clut.h
	$(CC) $(CFLAGS) clut.c -c

pgm.o: pgm.c pgm.h
	$(CC) $(CFLAGS) pgm.c -c

.phony: clean

clean:
	rm -f bw *.o results/*
