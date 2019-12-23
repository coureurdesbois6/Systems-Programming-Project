#include "vcs.h"
#include "endecryptermain.h"
#include <unistd.h>

#define NUM_OF_CMDS 6

void set_exe_path(char* path);
void cd(char** args);
void pwd(char** args);

void vcs(char** args);
void smonitor(char** args);
void endecrypter(char** args);
void findchange(char** args);

extern char* CMDS[];
extern void (*commands[NUM_OF_CMDS])(char**);
extern char* EXE_PATH;
extern char CURRENT_PATH[100];