flags=-02 -Wall -std=c2x
ldflags=-lbu

.PHONY: all clean

all: clean virtuvm

virtuvm: virtuvm.o
	cc $(flags) $^ -o $@ $(ldflags)

virtuvm.o: virtuvm.c virtuvm.h
	cc $(flags) -c $<

clean:
	rm -f *.o virtuvm
