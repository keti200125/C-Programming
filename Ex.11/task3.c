#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include<wait.h>
// Да се напише програма на Си, която прави канал между 2 команди 
// подадени като параметри в командния ред, като първата е без аргументи

int main(int argc, char *argv[]) {
  int fd[2];
  pipe(fd);

  if (argc < 3) {
    printf("prog com1 com2 args2 \n");
    exit(1);
  }

  int id = fork();
  if (id == -1) {
    printf("fork err\n");
    exit(1);
  } else if (id == 0) {
    close(fd[0]);
    close(1);
    dup(fd[1]);
    close(fd[1]);
    execlp(argv[1], argv[1], NULL);
  } else {
    int status;
    wait(&status);
    close(fd[1]);
    close(0);
    dup(fd[0]);
    close(fd[0]);
    execvp(argv[2], &argv[2]);
  }
}
/*
int main(int argc,char* argv[])
{
    if(argc<3)
    {
        perror("Not enough parameters");
        exit(1);
    }

    int fd[2];
    if(pipe(fd)== -1)
    {
        perror("Pipe couldn't open");
        exit(1);
    }

    int id =fork();

    if(id ==-1)
    {
        perror("Couldnt't fork");
        // printf("Couldn't fork");
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
        char* arguments[10];
        for(int i=2;i<argc;i++)
        {
            arguments[i-2]=(char*)(malloc(strlen(argv[i])));
            strcpy(arguments[i-2],argv[i]);
        }
        arguments[argc-2]=NULL;
        execvp(argv[2],arguments);
    }
}
*/