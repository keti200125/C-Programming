/*
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>
// Да се напише програма на Си, която прави канал между 3 команди.
// Например:  who | grep s81xxx | wc -l

int main()
{
    int fd[2];

    pipe(fd);

    int id = fork();

    if (id == -1)
    {
        perror("Couldn't fork");
        exit(1);
    }
    else if (id == 0)
    {
        close(fd[0]);
        //close(1);
        //dup(fd[1]);
        dup2(d[1],STDOUT_FILENO);
        close(fd[1]);
        if (execlp("who", "who", NULL) == -1)
        {
            printf("who err\n");
            exit(1);
        }
    }
    else
    {
        //int status;
        //wait(&status);
        wait(NULL);
        int id2=fork();
        if(id2==-1)
        {
            perror("File couldn't open");
            exit(1);
        }
        else if (id2 == 0)
        {
            close(1);
           //dup(fd[1]);
           //close(fd[1]);
           //dup2()

            close(0);
            dup(fd[0]);
            close(fd[0]);
            if (execlp("grep", "grep", "keti", NULL) == -1)
            {
                printf("grep err\n");
                exit(1);
            }
        }
        else
        {
            //int status;
            //wait(&status);
            wait(NULL);
            close(fd[1]);
            close(0);
            dup(fd[0]);
            close(fd[0]);
            if (execlp("wc", "wc", "-l", NULL) == -1)
            {
                printf("wc err\n");
                exit(1);
            }
        }
    }
}

*/