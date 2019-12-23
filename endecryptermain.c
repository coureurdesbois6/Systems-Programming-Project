#include "endecryptermain.h"

const char ENDE_ERR_MSG[] = "usage: endecrypter [file_name] [en]\nendecrypter [file_name] [de]\n";

void endecrypterfunc(char **args)
{
    int i = 0;
    while (args[i] != NULL)
    {
        i++;
    }

    //CHECK NUMBER OF ARGUMENTS
    if (i != 3)
    {
        printf("%s", ENDE_ERR_MSG);
    }
    else
    {

        FILE *num;
        num = fopen(args[1], "r");
        if (num == NULL)
        {
            printf("File couldn't found\n");
        }
        else
        {

            //GETTING FILE'S BYTE
            int Num_bytes;
            for (Num_bytes = 0; fgetc(num) != EOF; ++Num_bytes)
                ;
            fclose(num);

            //ENCRYPTION
            if (strcmp(args[2], "en") == 0)
            {

                char ch;
                FILE *file_main, *temp;

                file_main = fopen(args[1], "r");
                temp = fopen("clone.txt", "w");

                if (file_main == NULL)
                {
                    printf("File couldn't found\n");
                }
                else
                {

                    //ENCRYPTION PROGRESS
                    while (1)
                    {
                        ch = fgetc(file_main);
                        if (ch == EOF)
                        {
                            break;
                        }
                        else
                        {
                            ch = ch + 127;
                            fputc(ch, temp);
                        }
                    }
                    fclose(file_main);
                    fclose(temp);

                    file_main = fopen(args[1], "w");
                    temp = fopen("clone.txt", "r");

                    //TRANSFERRING ECRYPTED CHARS TO TEMP FILE
                    while (1)
                    {
                        ch = fgetc(temp);
                        if (ch == EOF)
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
            }

            //DECRYPTION
            if (strcmp(args[2], "de") == 0)
            {
                char ch;
                FILE *file_main, *temp;

                file_main = fopen(args[1], "w");
                temp = fopen("clone.txt", "r");

                if (file_main == NULL)
                {
                    printf("File couldn't found.\n");
                }
                else
                {

                    if (temp == NULL)
                    {
                        printf("File couldn't found.\n");
                    }
                    else
                    {

                        //DECRYPT PROCESS
                        while (1)
                        {
                            ch = fgetc(temp);
                            if (ch == EOF)
                                break;
                            else
                            {
                                ch = ch - 127;
                                fputc(ch, file_main);
                            }
                        }

                        fclose(file_main);
                        fclose(temp);
                        printf(".....File is decrypted.....\n");
                    }

                    //CHECKS SECOND ARGUMENT IS RIGHT OR WRONG
                }
                if (strcmp(args[2], "de") != 0 && strcmp(args[2], "en") != 0)
                {
                    printf("%s", ENDE_ERR_MSG);
                }
            }
            else
                printf("Size of file is %d bytes\n", Num_bytes);
        }
    }
}
