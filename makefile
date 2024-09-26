CC = gcc
CFLAGS = -Wall -g -lm
LDFLAGS = -lGL -lGLU -lglut

all: bmpReader

bmpReader: main.o bmp.o
	$(CC) -o bmpReader main.o bmp.o $(LDFLAGS)

main.o: main.c bmp.h
	$(CC) $(CFLAGS) -c main.c

bmp.o: bmp.c bmp.h
	$(CC) $(CFLAGS) -c bmp.c

clean:
	rm -f bmpReader *.o

