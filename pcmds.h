#include "vcs.h"
#define NUM_OF_CMDS 4

void set_exe_path(char* path);

void vcs(char** args);
void smonitor(char** args);
void cmd3(char** args);
void cmd4(char** args);

extern char* CMDS[];
extern void (*commands[4])(char**);
extern char* EXE_PATH;