

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include<wait.h>

//Output:                // file:
// A 1234512312345       // 12345
// 12345                 // 12345

int main(int argc, char *argv[])
{
    int fd, j, nb1, status;
    char buf[8];
    if (fork()) // if is the parent
    {
        wait(&status); //wait kid
        execlp("cat", "cat", argv[1], NULL); //terminal:12345 12345(new line)12345
    }
    else // if is kid
    {
        j = dup(1); // j->STDOUT
        fd = open(argv[1], O_RDWR); // open file
        nb1 = read(0, buf, 7); // read from STDIN
        write(j, buf, nb1); // print it on terminal
        nb1 = read(fd, buf, 5); // 12345
        write(1, buf, nb1); //terminal: 12345
        write(fd, "\n", 1); // 12345(new line)789
        write(fd, buf, nb1); // 12345(new line)12345
        write(j, buf, 3); // terminal: 123
        close(fd);    
        close(j);
        exit(0);
    }
}
