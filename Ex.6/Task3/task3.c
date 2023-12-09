// Да се напише програма на С, която получава като параметър
// команда (без параметри) и при успешното ѝ изпълнение,
// извежда на стандартния изход името на командата.

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <wait.h>

int main(int argc, char **argv)
{
    int status;
    if (fork() > 0)
    {
        wait(&status);
        printf("%s\n", argv[1]);
    }
    else
    {
        execlp(argv[1], argv[1], "task3.c", NULL);
    }
}
