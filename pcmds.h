void cmd1();
void cmd2();
void cmd3();
void cmd4();

char* CMDS[] = {"cmd1", "cmd2", "cmd3", "cmd4"};
void (*commands[4])(char**) = {cmd1, cmd2, cmd3, cmd4};

void cmd1(char** args){
    printf("cmd1 is called");
    //vcs(args)
}

void cmd2(char** args){
    printf("cmd2 is called");
}

void cmd3(char** args){
    printf("cmd3 is called");
}

void cmd4(char** args){
    printf("cmd4 is called");
}

