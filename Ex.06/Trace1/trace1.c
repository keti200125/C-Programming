
// Ouptput:
// Stoinostta na i=5
// Stoinostta na i=5 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include<wait.h>

int main(int argc, char *argv[])
{
    int fd, i = 4, nb1, status;
    char buf[5];
    if (fork() == 0) // if is kid
    {
        ++i;  // i=5
        printf("Stoinostta na i= %d\n", i); // Terminal: "Stoinostta na i=5" 
    }
    else
    {
        --i; // i=3
        exit(0); // оттук надолу родителят няма да изпълни нищо
        wait(&status);
        if (execlp("ls", "ls", "-l", NULL) == -1)
            i = i + 1;
        else
            printf("Stoinostta na i= %d\n", i);
    }
    printf("Stoinostta na i= %d\n", i); //  // Terminal: "Stoinostta na i=5" 
}
