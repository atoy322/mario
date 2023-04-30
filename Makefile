CFLAGS  := -Wall -O2 -I./include
LDFLAGS := -L./lib -l:pdcurses.a


ifeq ($(OS),)
	OS := $(shell uname)
endif


ifeq ($(OS),Windows_NT)
mario.exe: main.o
	gcc main.o -o mario.exe $(LDFLAGS)

main.o: main.c
	gcc -c main.c $(CFLAGS)
endif


.PHONY: clean
clean:
	-rm mario* *.o


