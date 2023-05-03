NAME := mario

ifeq ($(OS),Windows_NT)

CFLAGS  := -Wall -O2 -I./include
LDFLAGS := -L./lib -l:pdcurses.a

$(NAME).exe: main.o mario.o
	gcc main.o mario.o -o $(NAME).exe $(LDFLAGS)

main.o: main.c
	gcc -c main.c $(CFLAGS)

mario.o: mario.c
	gcc -c mario.c $(CFLAGS)

.PHONY: clean
clean:
	-rm $(NAME).exe *.o

else

CFLAGS  := -Wall -O2
LDFLAGS := -lcurses

$(NAME): main.o mario.o
	gcc main.o mario.o -o $(NAME) $(LDFLAGS)

main.o: main.c
	gcc -c main.c $(CFLAGS)

mario.o: mario.c
	gcc -c mario.c $(CFLAGS)

.PHONY: clean
clean:
	-rm $(NAME) *.o

endif


