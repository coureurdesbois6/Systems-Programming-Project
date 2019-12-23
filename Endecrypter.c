#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int endecrypter(char **args){
    int i = 0;
    while (args[i] != NULL) {
        i++;
    }

    
    
    /*char key[] = "MEF";
    char newKey[Num_bytes+1];
    int i,j;
    for(i,j = 0; i<Num_bytes; i++,j++ ){
        if(j == Num_bytes)
            j = 0;
        newKey[i] = key[i];
    }
    newKey[i] = '\0';*/

 

    if (i != 3)
    {
        printf("YOU HAVE TO GIVE 2 ARGUMENTS! FIRST ONE FILE NAME, SECOND ONE OPERATION!\n");
        exit (0);
    }

    FILE *num;
    num = fopen(args[1], "r");
    if(num == NULL){
        printf("File couldn't found\n");
        exit (0);
    }
    int Num_bytes;
    for(Num_bytes = 0; fgetc(num) != EOF; ++Num_bytes);
    fclose(num);

    if(strcmp(args[2],"en") == 0){
    
    char ch;
    FILE *file_main, *temp;

    file_main = fopen(args[1], "r");
    temp = fopen("clone.txt", "w");

    if(file_main == NULL){
        printf("File couldn't found\n");
        exit (0);
    }

    while(1){
        ch = fgetc(file_main);
        if(ch==EOF){
            break;
        }
        else
        {   
            ch = ch + 127;
            fputc(ch,temp);            
        }
        
    }

    /*for (i = 0; i < Num_bytes; ++i){
        ch = fgetc(file_main);
        if(ch == EOF){
            break;
        }
        else
        {
            tolower(ch);
            ch = ((ch + newKey[i]) % 26) + 'a';
        }
        
    }*/

    fclose(file_main);
    fclose(temp);

    file_main = fopen(args[1], "w");
    temp = fopen("clone.txt", "r");
    while (1){
        ch = fgetc(temp);
        if(ch==EOF)
            break;
        else
        {
            fputc(ch, file_main);
        }
        
    }
    fclose(file_main);
    fclose(temp);
    printf(".....File is encrypted.....\n");
    }
    
    if (strcmp(args[2], "de") == 0)
    {
    char ch;
	FILE *file_main, *temp;
	
	file_main = fopen(args[1], "w");
	temp = fopen("clone.txt", "r");

    if(file_main == NULL){
        printf("File couldn't found.\n");
        exit(0);
    }
    if(temp == NULL){
        printf("File couldn't found.\n");
        exit(0);
    }
	
	while(1)
	{
		ch = fgetc(temp);
		if(ch==EOF)
			break;
		else
		{
            ch = ch - 127;
			fputc(ch, file_main);

		}
	}
    
    /*for (i = 0; i < Num_bytes; ++i){
        ch = fgetc(file_main);
        if(ch == EOF){
            break;
        }
        else
        {
            tolower(ch);
            ch = (((ch - newKey[i])+26) % 26) + 'a';
        }
        
    }*/

	fclose(file_main);
	fclose(temp);
    printf(".....File is decrypted.....\n");
    }
    if(strcmp(args[2], "de") != 0 && strcmp(args[2], "en") != 0){
        printf("You have to give 'en' for encrypt, 'de' for decrypt as a second argument!\n");
	exit (0);
    }

   printf("Size of file is %d bytes\n", Num_bytes);

   return 0; 
}
