
ifeq ($(OS),Windows_NT)

CFLAGS  := -Wall -O2 -I./include
LDFLAGS := -L./lib -l:pdcurses.a

mario.exe: main.o
	gcc main.o -o mario.exe $(LDFLAGS)

main.o: main.c
	gcc -c main.c $(CFLAGS)

.PHONY: clean
clean:
	-rm mario.exe *.o

else

CFLAGS  := -Wall -O2
LDFLAGS := -lcurses

mario: main.o
	gcc main.o -o mario $(LDFLAGS)

mario.o: mario.c
	gcc -c main.c $(CFLAGS)

.PHONY: clean
clean:
	-rm mario *.o

endif


