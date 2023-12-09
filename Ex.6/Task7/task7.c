// Да се напише програма на С, която получава като параметър име на файл.
// Създава процес син, който записва стринга Hello във файла (ако не съществува,
// го създава, в противен случай го занулява), след което процеса родител прочита
// записаното във файла съдържание и го извежда на стандартния изход, добавяйки
// по един интервал между всеки два символа.

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <wait.h>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("error");
        exit(-1);
    }

    int fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0777);
    if (fd == -1)
    {
        printf("open err\n");
        exit(1);
    }

    int id = fork();
    char buff[2];

    if (id == -1)
    {
        printf("Error");
        exit(-1);
    }
    else if (id == 0)
    {
        write(fd, "Hello", 5);
    }
    else
    {
        int status;
        wait(&status);
        lseek(fd, 0, SEEK_SET); // get the fd back to the beginning of the file and then read
        while (read(fd, buff, 1) > 0)
        {
            write(1, buff, 1);
        }
    }
}