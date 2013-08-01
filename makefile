CC := gcc
RM := rm -f

all: ht_bin

ht_bin: ht.o unittest.o
	$(CC) -o ht -g ht.o unittest.o

ht.o: ht.c
	$(CC) -o ht.o -c ht.c

unittest.o: unittest.c
	$(CC) -o unittest.o -c unittest.c

clean:
	$(RM) ht.o unittest.o ht

