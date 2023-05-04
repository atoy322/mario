#include <signal.h>
#include "mario.h"

int main(int argc, char ** argv) {
    int w, h, id;
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
    signal(SIGINT, SIG_IGN);
    start_color();
    init_color(COLOR_RED, mred[0], mred[1], mred[2]);
    init_color(COLOR_GREEN, mgreen[0], mgreen[1], mgreen[2]);
    init_color(COLOR_YELLOW, mskin[0], mskin[1], mskin[2]);
    init_pair(1, COLOR_RED, COLOR_RED);
    init_pair(2, COLOR_GREEN, COLOR_GREEN);
    init_pair(3, COLOR_YELLOW, COLOR_YELLOW);
    //init_pair(4, COLOR_WHITE, COLOR_CYAN);
    //bkgd(COLOR_PAIR(4));

    getmaxyx(stdscr, h, w);

    for(int i=0; i<w+M_WIDTH; i++) {
        id = i%3;

        if((i == (w+M_WIDTH)/2) && (opt.stop)) {
            id = 3;
            erase();
            draw_mario(id, h-M_HEIGHT, (-M_WIDTH)+i);
            refresh();

            sleep(2);
        }

        erase();
        attrset(0);
        draw_mario(id, h-M_HEIGHT, (-M_WIDTH)+i);
        refresh();

        while((t - t_old)<delay) {
            t = gettime();
            usleep(100);
        }
        t_old = gettime();
    }

    //getch();

    endwin();

    //printf("COLOR_RED:%d\nCOLOR_GREEN:%d\nCOLOR_YELLOW:%d\nCOLOR_BLUE:%d\nCOLOR_CYAN:%d\nPAIR(1):%ld\nPAIR(2):%ld\nPAIR(3):%ld\nPAIR(4):%ld\n", COLOR_RED, COLOR_GREEN, COLOR_YELLOW, COLOR_BLUE, COLOR_CYAN, COLOR_PAIR(1), COLOR_PAIR(2), COLOR_PAIR(3), COLOR_PAIR(4));
    return 0;
}

