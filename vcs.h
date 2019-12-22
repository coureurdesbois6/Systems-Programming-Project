#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <ctype.h>
#include <dirent.h>

extern const char VCS_ERR_MSG[];

int file_edited(char* file_name1, char* file_name2);
int get_latest_version(char* repo, char* dir);
void create_version(char* repo, char* name);
void fetch(char* repo, char* dir);
void push(char* repo, char* dir, char* vername);
int check(char* file1, char* file2);
void create_repo(char* name);