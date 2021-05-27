CC = gcc
CFLAGS = -O2 -Wpedantic

default: ulimit_test

debug: CFLAGS = -g -Wpedantic
debug: ulimit_test

ulimit_test.o: ulimit_test.c
	$(CC) $(CFLAGS) -c ulimit_test.c -o ulimit_test.o

ulimit_test: ulimit_test.o
	$(CC) $(CFLAGS) ulimit_test.o -o ulimit_test

clean:
	-rm -f ulimit_test.o
	-rm -f ulimit_test
	
