CC = gcc
CFLAGS = -Wpedantic -g -Wall

A4: main.o parseFile.o P1_1.o 
	$(CC) $(CFLAGS) -o $@ main.o parseFile.o P1_1.o

main.o: main.c P1_1.o parseFile.o
	$(CC) $(CFLAGS) -c main.c -o $@
	
P1_1.o: P1_1.c P1.h parseFile.h parseFile.o
	$(CC) $(CFLAGS) -c P1_1.c -o $@

parseFile.o: parseFile.c parseFile.h
	$(CC) $(CFLAGS) -c parseFile.c -o $@

clean:
	rm *.o