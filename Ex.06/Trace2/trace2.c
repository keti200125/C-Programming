

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <wait.h>

#define CMD "wc -l $PWD"

int main(int argc, char *argv[])
{
    int fd, i = 2, nb1, status;
    char buf[5];
    if (fork() == 0) //if kid
    {
        ++i; // i =3
        exit(0); //end of the kid
    }
    else
    {
        if (execlp(CMD, CMD, NULL) == -1) // брой редове в $PWD, но тук аргументите са подадени грешно
        {
            --i;
            wait(&status);
            printf("Stoinostta na i= %d\n", i);
        }
        else
            printf("Stoinostta na i= %d\n", i); // 2
    }
}
