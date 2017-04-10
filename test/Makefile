# Komentari

PROGRAM = test
CC = g++
CFLAGS = -std=c++14 -Wall
LDFLAGS = -lm
OBJS =

test: mainTest.o MathTest.o
	$(CC) -o $@ $^ $(LDFLAGS)

mainTest.o: mainTest.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

MathTest.o: MathTest.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY : clean

clean:
	rm *.o *~
