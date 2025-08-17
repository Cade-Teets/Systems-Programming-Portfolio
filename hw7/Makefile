CC = g++
CFLAGS = -g -Wall -std=c++17

all: hw7

test: hw7
	./hw7

hw7: hw7.o Vector.o
	$(CC) $(CFLAGS) -o $@ $^

hw7.o: hw7.cc Vector.h
	$(CC) $(CFLAGS) -o $@ -c $<

Vector.o: Vector.cc Vector.h
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f hw7.o Vector.o hw7