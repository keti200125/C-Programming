// В цикъла се изпълнява команда, която брои буквите във файла aa.

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("File couldn't open");
        exit(-1);
    }

    char buf[16];

    for (int i = 5; i > 0; i--)
    {
        execlp("wc", "wc", "-c", argv[1], 0);
    }

    close(fd);
}

/*
 *
 * Output:
 *
 * abcde
 * fghi
 * jkl
 * mn
 * o
 *
 */