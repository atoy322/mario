#include <signal.h>
#include "mario.h"
#include "gcc.h"

bool stop_flag;
void ctrl_c_handler(int sig) {
    signal(SIGINT, SIG_IGN);
    stop_flag = true;
}

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
    signal(SIGINT, ctrl_c_handler);
    start_color();
    init_color(COLOR_RED, mred[0], mred[1], mred[2]);
    init_color(COLOR_GREEN, mgreen[0], mgreen[1], mgreen[2]);
    init_color(COLOR_YELLOW, mskin[0], mskin[1], mskin[2]);
    init_pair(1, COLOR_RED, COLOR_RED);
    init_pair(2, COLOR_GREEN, COLOR_GREEN);
    init_pair(3, COLOR_YELLOW, COLOR_YELLOW);

    getmaxyx(stdscr, h, w);

    for(int i=0; i<w+M_WIDTH; i++) {
        id = i%3;

        if(((i == (w+M_WIDTH)/2) && (opt.stop)) || stop_flag) {
            id = 3;
            stop_flag = false;
            erase();
            draw_mario(id, h-M_HEIGHT, (-M_WIDTH)+i);
            refresh();

            sleep(2);
            signal(SIGINT, ctrl_c_handler);
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

    endwin();

    return gcc(argc, argv);
}

