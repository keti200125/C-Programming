// Като първи параметър на програма на С се подава съществуващ празен файл.Напишете какво ще има записано
// във файла и какво ще бъде изведено на стандартния изход като резултат от изпълнението на дадения по - долу фрагмент от програма на С :
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>
int main(int argc, char *argv[])
{
    int fd, k, status;
    fd = open(argv[1], O_RDWR);
    if (fork())
    {
        wait(&status);
        dup(fd); 
        write(1, "who\n", 4);  // terminal: who\m
        execlp("who", "who", "-u", NULL); // display information about users who are currently logged into the system on termina;
        write(fd, "exam1\n", 5); //nothing
    }
    else // kid
    {
        close(1);
        dup(fd); // ako pishem na terminala, otiva v fd
        for (k = 0; k <= 3; k++) // 
            write(1, "exam2\n", 6); // exame2*4 in file.txt
    }
    execlp("pwd", "pwd", NULL); // print working directory int file.txt
}


// Terminal:
// who
// keti     pts/1        2024-01-17 17:16 02:28         464

// File:
// exam2
// exam2
// exam2
// exam2
// /home/keti/programming/Ex15
