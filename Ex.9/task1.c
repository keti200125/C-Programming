// Описание на примерните стъпки, включени в реализацията на  вариант на
// програма команден интерпретатор /КИ/ - изпълнение на команди с опции и аргументи

// Генериране на масив от указатели, сочещи отделните лексеми. При техното отделяне,
// когато се стигне до разделител се слага символа ‘\0‘. Подаване на този масив като
// втори аргумент на execvp.

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>
#include <string.h>

int main()
{
    while (1)
    {
        char buff[50];
        char *arguments[10];

        write(1, ">>>", 4);
        int cnt = 0;
        int i = 0;

        while (read(0, &buff[cnt], 1) > 0)
        {
            int len = strlen(buff);
            if (buff[cnt] == '\n')
            {
                buff[cnt] = '\0';
                //arguments[i]=buff;
                arguments[i] = (char*)(malloc(len + 1));
                strcpy(arguments[i],buff);
                cnt = 0;
                i++;
                break;
            }
            else if (buff[cnt] == ' ')
            {
                buff[cnt] = '\0';
                // memory allocation 
                // arguments= (char**)(malloc(length+1));
                arguments[i]= (char*)(malloc(len + 1));
                strcpy(arguments[i], buff);
                i++;
                cnt = 0;

            }
            else
            {
                cnt++;
            }
        }
        arguments[i] = NULL;

        if (strcmp(arguments[0], "quit") == 0)
        {
            for(int j=0;j<10;j++)
            {
                free(arguments[j]);
            }
            exit(0);
        }
        else
        {
            if (fork() == 0)
            {
                execvp(arguments[0], arguments);
                exit(1);
            }
            else
            {
                int status;
                wait(&status);
                if (status != 0)
                {
                    printf("ERROR: can't execute command\n");
                }
            }
        }
    }
}
