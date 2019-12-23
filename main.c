#include "pshell.h"

char* WELCOME_MESSAGE = "Current working directory is: /Users/CURRENT_USER\n"
"Custom shell made by Yigit SEZER and Efe ERTEKIN\n"
"Available commands: cd, pwd, vcs, smonitor, endecrypter, findchange\n";

int main(int argc, char **argv) {
    set_exe_path(argv[0]); //Set exe path to where the program is called
    system("clear");
    printf("%s", WELCOME_MESSAGE);
    main_loop(); //Shell main loop
    return 0;
}
