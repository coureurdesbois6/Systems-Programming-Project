#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pcmds.h"

#define EXTENSION_SIZE 16

void main_loop();
char* read_line();
char** split_line(char *line);
int execute(char** args);

void main_loop() {
    char *line;
    char **args;
    int status = 1;

    while (status) {
        printf("> ");
        line = read_line(); //Add line to history after this line
        args = split_line(line);
        status = execute(args);
        free(line);
        free(args);
    }
}

char* read_line(){
    int size = EXTENSION_SIZE;
    int position = 0;
    char *line = malloc(sizeof(char)*size);
    int c;

    while (1) {
        c = getchar();
        if (c == '\n' || c == EOF) {
            line[position] = '\0';
            return line;
        } else {
            line[position] = c;
        }
        position++;

        if (position >= size) {
            size += EXTENSION_SIZE;
            line = realloc(line, size);
            //????
        }
    }
}

char** split_line(char* line) {
    const char s[] = " ";
    char** args = malloc(sizeof(char*)*64);
    char *word;
    int position = 0;
   
    word = strtok(line, s);
    args[position] = word;
    position++;
    while(word != NULL) {
       word = strtok(NULL, s);
       args[position] = word;
       position++;
    }

    return args;
}

int execute(char** args) {
    for(int i = 0; i < sizeof(CMDS)/sizeof(char*); i++) {
        if(strcmp(CMDS[i], args[0]) == 0) {
            (*commands[i])(args);
            printf("\n");
        }
    }
}