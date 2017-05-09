PROGRAM = test
CC = g++
CFLAGS = -std=c++14 -Wall
LDFLAGS = -lm

test: mainTest.o MathTest.o FractionTest.o
	$(CC) -o $@ $^ $(LDFLAGS)

mainTest.o: mainTest.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

FractionTest.o: FractionTest.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

MathTest.o: MathTest.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY : clean

clean:
	rm *.o *~
