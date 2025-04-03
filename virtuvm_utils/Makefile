flags=-O3 -Wall -std=c2x -I.
ldflags=-fPIC -shared -ldl -D_GNU_SOURCE
libdir=/lib/x86_64-linux-gnu
incdir=/usr/include

all: clean virtuvm_utils.so

install: virtuvm_utils.so
	cp virtuvm_utils.so $(libdir)/libbu.so
	cp virtuvm_utils.h  $(incdir)
	ldconfig

virtuvm_utils.so: virtuvm_utils.o
	cc ${flags} $^ -o $@ ${ldflags}

virtuvm_utils.o: virtuvm_utils.c
	cc ${flags} -c $^ $(ldflags)

clean:
	rm -f virtuvm_utils.o virtuvm_utils.so
