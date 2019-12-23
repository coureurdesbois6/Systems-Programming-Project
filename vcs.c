#include "vcs.h"

const char VCS_ERR_MSG[] = "usage: vcs [-create] dir\nvcs [-fetch] [-check] proj-dir source-dir\nvcs [-push] proj-dir source ver-name\n";

//UNUSED FUNCTION CHECKING EQUALITY BETWEEN TWO FILES
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

//dir can be set to NULL, it sets string dir to latest version directory name
int get_latest_version(char* repo, char* dir) {
    struct dirent *de;
    char text[100];
    strcpy(text, "./");
    strcat(text, repo);

    DIR *dr = opendir(text);
  
    if (dr == NULL)
    { 
        printf("Could not open current directory"); 
        return 0; 
    } 
  
    FILE *fp;
    char buffer[100];
    int latest_ver = 99;

    while ((de = readdir(dr)) != NULL) {
        if(!strstr(de->d_name, ".")) {
            strcpy(text, "./");
            strcat(text, repo);
            strcat(text, "/");
            strcat(text, de->d_name);
            strcat(text, "/.ver");
            fp = fopen(text, "r");
            fseek(fp, 0, SEEK_SET);
            fread(buffer, sizeof(char)*10, 1, fp);
            if (atoi(buffer) > latest_ver) {
                latest_ver = atoi(buffer);
                if (dir != NULL)
                    strcpy(dir, de->d_name);
            }
            fclose(fp);
        }
    }

    closedir(dr);     
    return latest_ver;
}

//create version directory in repository with name name
void create_version(char* repo, char* name) {
    char text[100];
    FILE *fp;
    //struct stat st;
    strcpy(text, repo);
    strcat(text, "/.repo");
    fp = fopen(text, "r");
    if (fp == NULL) {
        printf("Directory is not a repository");
    } else {
        strcpy(text, "mkdir -p ");
        strcat(text, repo);
        strcat(text, "/");
        strcat(text, name);
        system(text);
        strcpy(text, repo);
        strcat(text, "/");
        strcat(text, name);
        strcat(text, "/.ver");
        fp = fopen(text, "w+");
        sprintf(text, "%d", get_latest_version(repo, NULL)+1);
        fputs(text, fp);
        fclose(fp);
    }
}

//Get latest version in repo, copy it to dir directory
void fetch(char* repo, char* dir) {
    char text[100];
    char latestver[100];
    FILE *fp;
    strcpy(text, repo);
    strcat(text, "/.repo");
    fp = fopen(text, "r");
    if (fp == NULL) {
        printf("Directory is not a repository");
    } else {
        get_latest_version(repo, latestver);
        strcpy(text, "cp -R ");
        strcat(text, "./");
        strcat(text, repo);
        strcat(text, "/");
        strcat(text, latestver);
        strcat(text, " ");
        strcat(text, dir);
        system(text);
    }
}

//Push dir to repo repository with version name vername
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
                create_version(repo, vername);
            } else {
                printf("Source directory doesn't exist.");
            }
        }
    }
}

//Show difference between two directories/repositories
void check(char* file1, char* file2) {
    FILE *p;
    char text[100];
    strcpy(text, "diff ");
    strcat(text, file1);
    strcat(text, " ");
    strcat(text, file2);
    //strcat(text, " | wc -l");
    //strcat(text, " | grep -c '[<>]'");
    //p = popen(text,"r");
    system(text);
}

//Create repository with given name/directory
void create_repo(char* name) {
    char text[100];
    FILE *fp;
    strcpy(text, "mkdir ./");
    strcat(text, name);
    system(text);
    strcpy(text, name);
    strcat(text, "/.repo");
    fp = fopen(text, "w+");
    fputs(name, fp);
    fclose(fp);
}