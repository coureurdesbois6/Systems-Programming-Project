#include "pcmds.h"
#include "vcs.h"
#include <unistd.h>

char* CMDS[] = {"vcs", "smonitor", "cmd3", "cmd4"};
void (*commands[4])(char**) = {vcs, smonitor, cmd3, cmd4};
char* EXE_PATH;

void set_exe_path(char* path){
    EXE_PATH = malloc(sizeof(path));
    EXE_PATH = path;
    //remove executable name from the path
    char *ptr = strrchr(EXE_PATH, '/');
    if (ptr) {
     *ptr = '\0';
    }
}

void vcs(char** args){
    int i = 0;
    while (args[i] != NULL) {
        i++;
    }
    i--; //i now indicates number of arguments passed to vcs
    
    if(i == 2) {
        if (strcmp(args[1], "-create") == 0) {
            create_repo(args[2]);
        } else {
            printf("%s", VCS_ERR_MSG);
        }
    } else if (i == 3) {
        if (strcmp(args[1], "-fetch") == 0) {
            fetch(args[2], args[3]);
        } else if (strcmp(args[1], "-check") == 0) {
            check(args[2], args[3]);
        } else {
            printf("%s", VCS_ERR_MSG);
        }
    } else if (i == 4) {
        if (strcmp(args[1], "-push") == 0) {
            push(args[2], args[3], args[4]);
        } else {
            printf("%s", VCS_ERR_MSG);
        }
    } else {
        printf("%s", VCS_ERR_MSG);
    }
}

void smonitor(char** args){
    char text[100];
    int i = 0;
    while (args[i] != NULL) {
        i++;
    }
    i--; //i now indicates number of arguments passed to smonitor
    strcpy(text, "cd ");
    strcat(text, EXE_PATH);
    strcat(text, "; ");
    /*
    chdir(EXE_PATH);
    char *execargs[i+2];
    execargs[0] = "./smonitor.sh";
    for(int j = 1; j < i+2; j++)
        execargs[j] = args[j];
    for(int j = 0; j < i+2; j++)
        printf("%s", execargs[j]);
    fork();
    execvp(execargs[0], execargs);
    */
    //FORGET EXEC
    i = 1;
    strcat(text, "./");
    strcat(text, args[0]);
    strcat(text, ".sh ");
    while (args[i] != NULL) {
        strcat(text, args[i]);
        strcat(text, " ");
        i++;
    }
    //printf("INSERTED: %s\n", text);
    system(text);
}

void cmd3(char** args){
    printf("cmd3 is called");
}

void cmd4(char** args){
    printf("cmd4 is called");
}

