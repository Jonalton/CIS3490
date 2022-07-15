CC = gcc
CFLAGS = -Wpedantic -g -Wall

all: A2Q1 A2Q2

A2Q2: A2Q2.o parseFile.o
	$(CC) $(CFLAGS) -o A2Q2 A2Q2.o parseFile.o

A2Q2.o: A2Q2.c parseFile.o
	$(CC) $(CFLAGS) -c A2Q2.c -o $@

A2Q1: A2Q1.o parseFile.o
	$(CC) $(CFLAGS) -o A2Q1 A2Q1.o parseFile.o

A2Q1.o: A2Q1.c parseFile.o
	$(CC) $(CFLAGS) -c A2Q1.c -o $@

parseFile.o: parseFile.c parseFile.h
	$(CC) $(CFLAGS) -c parseFile.c -o $@

clean:
	rm *.o