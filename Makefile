CC = gcc
CFLAGS = -Wall -Werror -pedantic -g

all: main

main: main.c allocator.c
	$(CC) $(CFLAGS) -o $@ $^ 

clean:
	rm -f main *~