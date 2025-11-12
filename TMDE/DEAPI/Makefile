flags=-O2 -Wall -std=c23 -I.
soflags=-ldl -shared -fPIC
ldflags=

.PHONY: clean

all: clean DiskEm.o

DEAPI.so: DiskEm.o Hfunc.o
	cc $(flags) $(CFLAGS) $(soflags) $^ -o $@

DiskEm.o: DiskEm.c DiskEm.h 
	cc $(flags) $(CFLAGS) $(soflags) -c $<

Hfunc.o: Hfunc.c Hfunc.h Head.h
	cc $(flags) $(CFLAGS) $(soflags) -c $<

clean:
	rm -f *.o