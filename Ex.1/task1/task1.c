
// Да се напише програма на C, която реализира командата cp файл1 файл2

#include <stdio.h>  // print()
#include <fcntl.h>  // open file
#include <unistd.h> //reading from file
#include <stdlib.h> // exit(-1)

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Mistake");
        exit(1);
    }
    int fd1 = open(argv[1], O_RDONLY);
    if (fd1 == -1)
    {
        perror("File couldn't open");
        exit(-1);
    }

    char buffer[256];

    ssize_t symbols = read(fd1, buffer, 256);

    int fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 777);
    if (fd2 == -1)
    {
        perror("File couldn't open");
        exit(-1);
    }

    write(fd2, buffer, symbols);

    close(fd1);
    close(fd2);
    return 0;
}
