#include "pshell.h"

//Main loop always reading input before the return key
void main_loop() {
    char *line;
    char **args;
    int status = 0; //0 indicating no error

    while (!status) {
        printf("> ");
        line = read_line(); //TODO: Add line to `history` after this line
        if (strcmp(line, " ") == 0 || strlen(line) == 0) {
            continue;
        }
        args = split_line(line);
        status = execute(args);
        free(line); //free both line and args after executed proccess is finished
        free(args);
    }
}

//read every keystroke to a string
//allows flexible sized input string
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

//parse given input to arguments
//(or just split it)
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

//call the function corresponding to
//given function name, passing the arguments
int execute(char** args) {
    for(int i = 0; i < NUM_OF_CMDS; i++) {
        if(strcmp(CMDS[i], args[0]) == 0) {
            (*commands[i])(args);
            return 0;
        }
    }
    printf("%s: command not found\n", args[0]);
    return 0;
}