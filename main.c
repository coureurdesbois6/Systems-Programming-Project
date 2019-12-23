#include "pshell.h"

int main(int argc, char **argv) {
    set_exe_path(argv[0]);
    system("clear");
    printf("Current working directory is: /Users/CURRENT_USER\nCustom shell made by Yigit SEZER and Efe ERTEKIN\nAvailable commands: cd, vcs, smonitor, endecrypter\n");
    main_loop();
    return 0;
}
