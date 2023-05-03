#include "mario.h"

void draw_mario(int id, int py, int px) {

    int w, h;
    char color;

    getmaxyx(stdscr, h, w);

    for(int y=0; y<M_HEIGHT; y++) {
        for(int x=0; x<M_WIDTH; x++) {

            if((py+y >= h) || (px+x >= w) || (py+y < 0) || (px+x < 0)) {
                continue;
            }
            move(py+y, px+x);
            color = marios[id][y][x];

            if(color == 0) {
                attrset(0);
                addstr(" ");
            } else {
                attrset(COLOR_PAIR(color));
                addstr(" ");
            }
        }
    }
}


double gettime(void) {
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    return (double)ts.tv_sec + (double)ts.tv_nsec*1e-9;
}

void parse(int argc, char ** argv, options_t * op) {
    op->fast = false;

    for(int i=0; i<argc; i++) {
        if(argv[i][0] != '-')
            continue;

        if(argv[i][1] == 'f') {
            op->fast = true;
        }
    }
}
