flags=-O2 -Wall -std=c2x
# ldflags=-lbu

.PHONY: all clean

all: clean virtuvm

virtuvm: virtuvm.o
	# cc $(flags) $^ -o $@ $(ldflags)
	cc $(flags) $^ -o $@ 

virtuvm.o: virtuvm.c virtuvm.h
	cc $(flags) -c $<

clean:
	rm -f *.o virtuvm
