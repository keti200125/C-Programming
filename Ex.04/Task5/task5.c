//  В зад 5 след EXAMPLE се пранасочва стандартния изход в подадения като
//  параметър файл и числата от 1 до 10 излизат във файла. След това
//  се възстановява стандартния изход и HELLO  отново е на екрана.

//itoa()

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("No input file\n");
        exit(-1);
    }

    int out = dup(1);

    int fd = open(argv[1], O_WRONLY | O_CREAT, 0777);
    if (fd == -1)
    {
        perror("File couldn't open");
        exit(-1);
    }

    for (int i = 1; i < 11; i++)
    {
        write(1, "EXAMPLE ", 8);
    }

    int fd2 = dup2(fd, 1);
    char buff[3];

    for (int i = 1; i < 11; i++)
    {
        sprintf(buff,"%d ",i);
        write(1,buff,2);
    }

    dup2(out, 1);

    for (int i = 1; i < 11; i++)
    {
        write(1, "HELLO ", 6);
    }

    close(fd);
    close(out);
}
