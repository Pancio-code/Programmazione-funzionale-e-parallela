CC     = gcc
CFLAGS = -O1 -Wall

ifeq ($(shell uname -s),Linux)
		LFLAGS = -lOpenCL
endif

ifeq ($(shell uname -s),Darwin)
		LFLAGS = -framework OpenCL
endif

px4: main.o clut.o pgm.o px4.o
	$(CC) $(CFLAGS) main.o clut.o pgm.o px4.o \
        -o px4 $(LFLAGS)

main.o: main.c clut.h px4.h pgm.h
	$(CC) $(CFLAGS) main.c -c

px4.o: px4.c px4.h clut.h
	$(CC) $(CFLAGS) px4.c -c

clut.o: clut.c clut.h
	$(CC) $(CFLAGS) clut.c -c

pgm.o: pgm.c pgm.h
	$(CC) $(CFLAGS) pgm.c -c

.phony: clean

clean:
	rm -f px4 *.o results/*
