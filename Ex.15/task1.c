/*. Напишете програма на C, която получава при стартиране два параметърa –команда без опции
 и аргументи и файл. Прочита от стандартния вход команда също без опции и аргументи. Ползвайки
 системните примитиви за работа с файлове и процеси в Linux, изпълнява канал между прочетената
 от стандартния вход команда и подадената като първи параметър такава. Накрая извежда кодът на
 завършване на канала на екрана и имената на двете команди в подадения като параметър файл.*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        perror("Not enough aguments");
        exit(1);
    }
    int fdo = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (fdo == -1)
    {
        perror("File couldn't open");
        exit(1);
    }
    char command[30];
    int i = 0;
    write(1, ">>>", 3);
    while (read(0, &command[i], 1) > 0)
    {
        if (command[i++] == '\n')
        {
            command[i - 1] = '\0';
            break;
        }
    }

    int fd[2];

    if (pipe(fd) == -1)
    {
        perror("Pipe couldn't open");
        exit(1);
    }

    int pid = fork();

    if (pid == -1)
    {
        perror("Couldn't fork");
        exit(1);
    }
    else if (pid == 0)
    {
        close(fd[0]);
        close(1);
        dup(fd[1]);
        close(fd[1]);
        if(execlp(argv[1], argv[1], NULL)==-1)
        {
            perror("FIRST COMMAND");
            exit(1);
        }
    }
    else
    {
        wait(NULL);
        int p;
        if (p = fork()) // parent
        {
            int status;
            waitpid(pid, &status, 0);
            printf("Status code = %d", 0);
            write(fdo, argv[1], strlen(argv[1]));
            write(fdo, " ", 1);
            write(fdo, command, strlen(command));
        }
        else
        {
            close(fd[1]);
            close(0);
            dup(fd[0]);
            close(fd[0]);
            if(execlp(command, command, NULL) == -1)
            {
                perror("COMMAND 2 Problem");
                exit(1);
            }
        }
    }
}