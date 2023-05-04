#ifndef MARIO_H
#define MARIO_H

#include <curses.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>

#define M_WIDTH  30
#define M_HEIGHT 16


extern char marios[4][16][30];
extern short mred[3];
extern short mgreen[3];
extern short mskin[3];

typedef struct {
    bool fast;
    bool stop;
} options_t;

void draw_mario(int, int, int);
double gettime(void);
void parse(int, char **, options_t *);

#endif
