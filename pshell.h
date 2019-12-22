#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pcmds.h"
#define EXTENSION_SIZE 16

void main_loop();
char* read_line();
char** split_line(char *line);
int execute(char** args);