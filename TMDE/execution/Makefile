flags=-O2 -Wall -std=c23 -I../DEAPI
soflags=-ldl -shared -fPIC
ldflags=

.PHONY: clean clean-DEAPI

all: clean clean-DEAPI execute.com

execute.com: execute.o ../DEAPI/DEAPI.so
	cc $(flags) $^ -o $@ $(ldflags)

../DEAPI/DEAPI.so: ../DEAPI/DiskEm.c ../DEAPI/DiskEm.h ../DEAPI/Head.h ../DEAPI/Hfunc.c ../DEAPI/Hfunc.h
	$(MAKE) -C ../DEAPI DEAPI.so "CFLAGS=$(flags)"

execute.o: execute.c execute.h
	cc $(flags) -c $<

clean-DEAPI:
	$(MAKE) -C ../DEAPI clean

clean: 
	rm -f *.o execute.com
