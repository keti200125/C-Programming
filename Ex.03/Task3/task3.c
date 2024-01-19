// Да се напише програма на Си, която получава като параметри
// в командния ред число и име на файл. Програмата извежда на
// стандартиния изход съдължанието на файла от указания от числото ред.

// atoi(..) -convert string to integer

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int line = atoi(argv[1]);
    int currLine = 1;
    char buf[2];

    int fd = open(argv[2], O_RDONLY);
    if (fd == -1)
    {
        perror("File couldn't open");
        exit(-1);
    }

    while (read(fd, buf, 1) > 0)
    {
        if (currLine > line)
        {
            break;
        }
        if (currLine == line)
        {
            write(1, buf, 1);
        }
        if (buf[0] == '\n')
        {
            currLine++;
        }
    }

    close(fd);
}
