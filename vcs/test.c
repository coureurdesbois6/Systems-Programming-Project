#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
    FILE *p;
    char ch;

    int x;
    p = popen("diff vro Project2/ver2 | wc -l","r");   /* DOS */
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
    printf("OUT%d", x);
    
    return x;
}