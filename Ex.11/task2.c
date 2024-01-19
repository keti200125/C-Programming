#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
// Да се напише програма на Си, която прави канал между 2 команди
// подадени като параметри в командния ред/ без опции и аргументи/.

int main(int argc, char* argv[])
{
    if(argc<3)
    {
        perror("Not enough parameters");
        exit(1);
    }
    int fd[2];
    if(pipe(fd)== -1)
    {
        perror("Couldn't open pipe");
        exit(1);
    }

    int id = fork();

    if(id == -1)
    {
        perror("Couldn't fork");
        exit(1);
    }
    else if(id == 0)
    {
        close(fd[0]);
        close(1);
        dup(fd[1]);
        close(fd[1]);
        execlp(argv[1],argv[1],NULL);
    }
    else
    {
        close(fd[1]);
        close(0);
        dup(fd[0]);
        close(fd[0]);
        execlp(argv[2],argv[2],NULL);
    }

}