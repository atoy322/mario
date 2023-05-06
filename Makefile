NAME := gccc

ifeq ($(OS),Windows_NT)

CFLAGS  := -Wall -O2 -I./include
LDFLAGS := -L./lib -l:pdcurses.a

$(NAME).exe: main.o mario.o gcc.o
	gcc main.o mario.o gcc.o -o $(NAME).exe $(LDFLAGS)

main.o: main.c
	gcc -c main.c $(CFLAGS)

mario.o: mario.c mario.h
	gcc -c mario.c $(CFLAGS)

gcc.o: gcc.c gcc.h
	gcc -c gcc.c $(CFLAGS)

.PHONY: clean
clean:
	-rm $(NAME).exe *.o

else

CFLAGS  := -Wall -O2
LDFLAGS := -lcurses

$(NAME): main.o mario.o gcc.o
	gcc main.o mario.o gcc.o -o $(NAME) $(LDFLAGS)

main.o: main.c
	gcc -c main.c $(CFLAGS)

mario.o: mario.c mario.h
	gcc -c mario.c $(CFLAGS)

gcc.o: gcc.c gcc.h
	gcc -c gcc.c $(CFLAGS)

.PHONY: clean
clean:
	-rm $(NAME) *.o

endif


