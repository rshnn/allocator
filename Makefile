CC = gcc
CFLAGS = -Wall -Werror -g

all: testcase01 testcase02 testcase03 testcase04 testcase05 testcase06

testcase01: testcase01.c allocator.c
	$(CC) $(CFLAGS) -o $@ $^ 

testcase02: testcase02.c allocator.c
	$(CC) $(CFLAGS) -o $@ $^ 

testcase03: testcase03.c allocator.c
	$(CC) $(CFLAGS) -o $@ $^ 

testcase04: testcase04.c allocator.c
	$(CC) $(CFLAGS) -o $@ $^ 

testcase05: testcase05.c allocator.c
	$(CC) $(CFLAGS) -o $@ $^ 

testcase06: testcase06.c allocator.c
	$(CC) $(CFLAGS) -o $@ $^ 

clean:
	rm -f testcase01 testcase02 testcase03 testcase04 testcase05 testcase06