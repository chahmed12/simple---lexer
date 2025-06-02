CC = gcc
CFLAGS = -Wall

all: lexer

lexer: lexer.o main.o
	$(CC) $(CFLAGS) -o lexer lexer.o main.o

lexer.o: lexer.c lexer.h
	$(CC) $(CFLAGS) -c lexer.c

main.o: main.c lexer.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o lexer