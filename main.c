#include "mario.h"

int main(int argc, char ** argv) {
    int w, h;
    double t, t_old, delay=0.05;
    options_t opt;

    t = gettime();
    t_old = gettime();

    parse(argc, argv, &opt);
    if(opt.fast) {
        delay = 0.01;
    }

    initscr();
    curs_set(0);
    start_color();
    init_color(COLOR_RED, mred[0], mred[1], mred[2]);
    init_color(COLOR_GREEN, mgreen[0], mgreen[1], mgreen[2]);
    init_color(COLOR_YELLOW, mskin[0], mskin[1], mskin[2]);
    init_pair(1, COLOR_RED, COLOR_RED);
    init_pair(2, COLOR_GREEN, COLOR_GREEN);
    init_pair(3, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(4, COLOR_BLUE, COLOR_BLUE);
    bkgd(COLOR_PAIR(4));

    getmaxyx(stdscr, h, w);

    for(int i=0; i<w+M_WIDTH; i++) {
        clear();
        draw_mario(i%3, h-M_HEIGHT, (-M_WIDTH)+i);
        refresh();

        while((t - t_old)<delay) {
            t = gettime();
            usleep(100);
        }
        t_old = gettime();
    }

    //getch();

    endwin();

    return 0;
}

