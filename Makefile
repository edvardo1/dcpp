CC?=cc
CFLAGS=-Wall -std=c99
PROGRAMNAME=dcpp

dcpp: main.o exinst.o parse.o
	$(CC) $(CFLAGS) -o $(PROGRAMNAME) *.o

main.o: def.h main.c
	$(CC) $(CFLAGS) -c main.c

exinst.o: def.h exinst.h exinst.c
	$(CC) $(CFLAGS) -c exinst.c

parse.o: def.h parse.h parse.c
	$(CC) $(CFLAGS) -c parse.c

clean:
	rm *.o dcpp