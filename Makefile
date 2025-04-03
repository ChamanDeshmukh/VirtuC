flags=-O2 -Wall -std=c2x
# ldflags=-lbu

.PHONY: all clean

all: clean virtuvm

$(pwd)/virtuvm_utils/virtuvm_utils.o: $(pwd)/virtuvm_utils/virtuvm_utils.c $(pwd)/virtuvm_utils/virtuvm_utils.h	
	(cd ./virtuvm_utils/ && make)
virtuvm: virtuvm.o $(pwd)/virtuvm_utils/virtuvm_utils.o
	# cc $(flags) $^ -o $@ $(ldflags)
	cc $(flags) $^ -o $@ 

virtuvm.o: virtuvm.c virtuvm.h
	cc $(flags) -c $<

clean:
	rm -f *.o virtuvm
