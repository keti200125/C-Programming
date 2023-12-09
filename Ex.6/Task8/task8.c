// Да се напише програма на С, която получава като параметри имена
// на два файла. В зад 6 пренасочва изхода на процеса дете във втория
// файл (ако не съществува, го създава, в противен случай добавя в него)

// ?

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <wait.h>

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        printf("error");
        exit(-1);
    }

    int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    int fd2 = open(argv[2], O_WRONLY | O_CREAT | O_APPEND, 0777);
    if (fd == -1)
    {
        printf("open err\n");
        exit(1);
    }

    int id = fork();

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
        write(fd2, "Hello", 5);
    }

    close(fd);
    close(fd2);
}