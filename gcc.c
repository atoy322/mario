#include "gcc.h"
#include <string.h>
#include <stdlib.h>

int gcc(int argc, char ** argv) {
    char cmdline[256] = "gcc";

    for(int i=1; i<argc; i++) {
        strcat(cmdline, " ");
        strcat(cmdline, argv[i]);
    }

    return system(cmdline);
}
