flags=-O2 -Wall -std=c2x -I./virtuvm_utils/
# ldflags=-lbu
ldflags=

.PHONY: all clean

all: virtuvm

./virtuvm_utils/virtuvm_utils.o: ./virtuvm_utils/virtuvm_utils.c ./virtuvm_utils/virtuvm_utils.h	
	(cd ./virtuvm_utils/ && make)

virtuvm: virtuvm.o ./virtuvm_utils/virtuvm_utils.o
	cc $(flags) $< -o $@ $(ldflags) ./virtuvm_utils/virtuvm_utils.o

virtuvm.o: virtuvm.c virtuvm.h
	cc $(flags) -c $<

clean:
	rm -f *.o virtuvm
