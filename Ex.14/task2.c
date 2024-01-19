// Напишете програма на C, която ползвайки системните примитиви за работа с файлове
// и процеси в Linux, чрез механизма на  канал извежда общия брой на логическите
// терминали, на който работят потребителите в сесия. Ако каналът е завършил успешно, (с код 0)
// на екрана с подходящо съобщение излиза информацията от файла, подаден като параметър.
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <wait.h>
int main()
{
    int fd[2];
    pipe(fd);

    int id1 = fork();

    if (id1 == 0) // child
    {
        close(fd[0]);
        close(1);
        dup(fd[1]);
        close(fd[1]);
        execlp("who", "who", NULL);
    }
    else // parent
    {
        close(fd[1]); // !!!!!!!!!!!
        int status1;
        waitpid(id1, &status1, 0);
        int id2 = fork();
        if (id2==0) //kid
        {
            close(0);
            dup(fd[0]);
            close(fd[0]);
            execlp("wc", "wc", "-l", NULL);
        }
        else
        {
            int status2;
            waitpid(id2, &status2, 0);
            if (status2 == 0)
            {
                printf("Everything is great");
            }
        }
    }
}