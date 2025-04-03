flags=-O3 -Wall -std=c2x -I.
ldflags=-fPIC -shared -ldl -D_GNU_SOURCE
libdir=/lib/x86_64-linux-gnu/
incdir=/usr/include

all: clean virtuvm_utils.so

install: virtuvm_utils.so
	cp birchutils.so $(libdir)/libbu.so
	cp birchutils.h  $(incdir)
	ldconfig

birchutils.so: virtuvm_utils.o
	cc ${flags} $^ -o $@ ${ldflags}

birchutils.o: virtuvm_utils.c
	cc ${flags} -c $^ $(ldflags)

clean:
	rm -f virtuvm_utils.o virtuvm_utils.so
