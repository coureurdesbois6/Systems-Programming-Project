#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <ctype.h>
#include <dirent.h>

int file_edited(char* file_name1, char* file_name2) {
    int c = 0;
    int c2 = 0;
    int same = 1;
    FILE *file;
    FILE *file2;
    file = fopen(file_name1, "r");
    file2 = fopen(file_name2, "r");
    if (file && file2) {
        while (c != EOF && c2 != EOF) {
            c = getc(file);
            c2 = getc(file2);
            if (c != c2){
                return 1;
            }
        }
        fclose(file);
    }
    return 0;
}

void create_version() {
    
}

void fetch(char* repo, char* dir, char* vername) {

}

void push(char* repo, char* dir, char* vername) {
    char text[100];
    FILE *fp;
    struct stat st;
    strcpy(text, repo);
    strcat(text, "/.repo");
    fp = fopen(text, "r");
    if (fp == NULL) {
        printf("Directory is not a repository");
    } else {
        strcpy(text, repo);
        strcat(text, "/");
        strcat(text, vername);
        if(stat(text,&st) == 0) {
            printf("Version already exists");
        } else {
            if(stat(dir,&st) == 0) {
                strcpy(text, "cp -R ");
                strcat(text, dir);
                strcat(text, " ");
                strcat(text, repo);
                strcat(text, "/");
                strcat(text, vername);
                system(text);
            } else {
                printf("Source directory doesn't exist.");
            }
        }
    }
}

int is_same(char* file1, char* file2) {
    FILE *p;
    char ch;
    char text[100];
    int x;

    strcpy(text, "diff ");
    strcat(text, file1);
    strcat(text, " ");
    strcat(text, file2);
    strcat(text, " | wc -l");
    p = popen(text,"r");   /* DOS */
    //fprintf(fp, "plot sin(x)\n");
    if( p == NULL)
    {
        puts("Unable to open process");
    }
    while( (ch=fgetc(p)) != EOF) {
        if(isdigit(ch) != 0)
            x+=(char)ch;
    }
    pclose(p);
    if (x == 49) {
        return 1;
        printf("Project is up to date.");
    } else {
        return 0;
        printf("Project is not up to date.");
    }
}

void check() {
}

void create(char* name) {
    char text[100];
    FILE *fp;
    strcpy(text, "mkdir ");
    strcat(text, name);
    system(text);
    strcpy(text, name);
    strcat(text, "/.repo");
    fp = fopen(text, "w+");
    fputs(name, fp);
    fputs("\n100", fp);
    fclose(fp);
}

int main(){
    int x = file_edited("test.txt", "test2.txt");
    //if(*args[1] == "-fetch")
    //system("cp -R br br2");
    char* project = "Project2";
    //push("Project2", "asdfd", "ver2");
    //create(name);
    if (is_same("vro", "Project2/ver2"))
        printf("yesh");
    return 0;
}