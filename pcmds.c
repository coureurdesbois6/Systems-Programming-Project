#include "pcmds.h"

char* CMDS[] = {"cd", "pwd", "vcs", "smonitor", "endecrypter", "findchange"};
void (*commands[NUM_OF_CMDS])(char**) = {cd, pwd, vcs, smonitor, endecrypter, findchange};
char* EXE_PATH;
char CURRENT_PATH[100];


//Set the executable path
//Called in main on startup
void set_exe_path(char* path){
    EXE_PATH = malloc(sizeof(path));
    EXE_PATH = path;
    //remove executable name from the path
    char *ptr = strrchr(EXE_PATH, '/');
    if (ptr) {
     *ptr = '\0';
    }
}

/*
    CURRENT_PATH together with EXE_PATH resolves some complications
    made during the system() calls by ensuring the shell scripts and
    C functions work in desired paths.
*/

//Prints current working directory
void pwd(char** args) {
    getcwd(CURRENT_PATH, sizeof(CURRENT_PATH));
    printf("%s\n", CURRENT_PATH);
}

//Change current working directory
void cd(char** args){
    struct stat st;
    if(stat(args[1],&st) != 0) {
        printf("Directory doesn't exist\n");
    } else {
        char cwd[100];
        getcwd(cwd, sizeof(cwd));
        strcat(cwd, "/");
        strcat(cwd, args[1]);
        chdir(cwd);
        getcwd(cwd, sizeof(cwd));
        printf("current working directory: %s\n", cwd);
        strcpy(CURRENT_PATH, cwd);
    }
}

// DEVELOPER NOTE:
// INSERTING / BEFORE DIRECTORY NAME CREATES SEGMENTATION
// PASS DIRECTORY ARGUMENTS USING EXE_PATH
// OR IMPLEMENT CHANGE DIRECTORY


//vcs function parses and calls selected functions
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

//calls smonitor shell script
void smonitor(char** args){
    char text[100];
    int i = 1;
    strcpy(text, EXE_PATH);
    strcat(text, "/");
    strcat(text, args[0]);
    strcat(text, ".sh ");
    while (args[i] != NULL) {
        strcat(text, args[i]);
        strcat(text, " ");
        i++;
    }
    //printf("INSERTED: %s\n", text); //Indicates what is passed to system()
    system(text);
}

//calls endecrypter main function
//args are parsed in the endecrypter main function endecrypterfunc
void endecrypter(char** args){
    endecrypterfunc(args);
}

//calls findchange shell script
void findchange(char** args){
    char text[150];
    int i = 1;
    strcpy(text, EXE_PATH);
    strcat(text, "/");
    strcat(text, args[0]);
    strcat(text, ".sh ");
    while (args[i] != NULL) {
        if(i == 3) {
            strcat(text, CURRENT_PATH);
            strcat(text, "/");
        }
        strcat(text, args[i]);
        strcat(text, " ");
        i++;
    }
    //printf("INSERTED: %s\n", text); //Indicates what is passed to system()
    system(text);
}