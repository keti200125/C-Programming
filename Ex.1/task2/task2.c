// Да се напише програма на C, която реализира командата cat (без параметри)

#include <stdio.h>  //print
#include <fcntl.h>  //open file
#include <unistd.h> //read and write from file
#include <stdlib.h> // exit

int main(int argc, char *argv[])
{
    if (argc < 1)
    {
        printf("No params");
        exit(1);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("No such fiile or directory");
        exit(-1);
    }

    char buffer[256];

    ssize_t symbols = read(fd, buffer, 256);

    printf("%s\n", buffer);

    close(fd);
}