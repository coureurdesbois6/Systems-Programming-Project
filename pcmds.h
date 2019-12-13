void cmd1();
void cmd2();
void cmd3();
void cmd4();

char* CMDS[] = {"cmd1", "cmd2", "cmd3", "cmd4"};
void (*commands[4])() = {cmd1, cmd2, cmd3, cmd4};

void cmd1(){
    printf("cmd1 is called");
}

void cmd2(){
    printf("cmd2 is called");
}

void cmd3(){
    printf("cmd3 is called");
}

void cmd4(){
    printf("cmd4 is called");
}

