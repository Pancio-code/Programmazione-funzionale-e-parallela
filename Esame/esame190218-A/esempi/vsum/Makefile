CC=gcc
FLAGS=-O1 -Wall -msse4.2

all: sum sum_sse

sum: sum.h sum.c sum_main.c
	$(CC) $(FLAGS) sum.c sum_main.c -o sum

sum_sse: sum.h sum_sse.c sum_main.c
	$(CC) $(FLAGS) sum_sse.c sum_main.c -o sum_sse

.phony: clean test

test:
	@echo "--- Test sum:"
	@time -p ./sum
	@echo "--- Test sum_sse:"
	@time -p ./sum_sse

clean:
	rm -f sum sum_sse
