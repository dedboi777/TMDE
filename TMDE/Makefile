flags=-O2 -Wall -std=c23 -I.
soflags=-ldl -shared -fPIC
ldflags=

.PHONY: clean

all: clean DiskEm.o

DiskEm.o: DiskEm.c DiskEm.h os.h osapi.h
	cc $(flags) $(CFLAGS) $(soflags) -c $<
	
clean:
	rm -f *.o