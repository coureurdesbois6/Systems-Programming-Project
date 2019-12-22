#include "pshell.h"

int main(int argc, char **argv) {
    set_exe_path(argv[0]);
    printf("Current working directory is: /Users/CURRENT_USER\n");
    main_loop();
    return 0;
}
