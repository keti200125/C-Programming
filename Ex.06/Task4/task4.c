// Да се напише програма на С, която получава като параметър
// команда с опции и аргумeнти. При успешното ѝ изпълнение,
// извежда на стандартния изход кода на завършане.

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <wait.h>

// think



int main(int argc, char **argv)
{
    char* args[10];
    for(int i=1;i<argc;i++)
    {
        args[i]=argv[i];
        //printf("%s ",args[i]);
    }

    int status;
    if (fork())
    {
        int end_code = wait(&status);
        printf("\nEnd code: %d", end_code);
    }
    else
    {
        if (execvp(argv[1], args) == -1)  // &argv[1] instead of args
        {
            printf("NO");
            exit(1);
        }
    }

}