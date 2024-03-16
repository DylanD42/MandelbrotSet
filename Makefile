CC = g++
CFLAGS = -g -Wall -Wextra

default: mandlebrot

mandlebrot: main.o
	$(CC) $(CFLAGS) -o mandlebrot main.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp
clean:
	$(RM) mandlebrot *.o *~
