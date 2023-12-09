// Горните 2 задачи като се промени съдържанието на файла aa на следното – abcdefghij\n.

#include <fcntl.h>  //open
#include <unistd.h> //read
#include <stdio.h>  //print
#include <stdlib.h> //exit(-1)

int main()
{
    int fd = open("aa.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("File couldn't open");
        exit(-1);
    }

    char buf[16];
    int i;
    for (i = 5; i > 0; i--)
    {
        //read(fd, buf, i);
        //printf("%s\n", buf); //print for strings
         read(fd,buf,i);
        write(1,buf,i);
        write(1,"\n",1);

    }

    close(fd);
}

/*
 *
 * Output print:
 *
 * abcde
 * fghie
 * j
 * hie
 * j
 * hie
 *j
 * hie
 * 
 * Output write:
 * 
 * abcde
 * fghi
 * j
 * h
 * j
 * 
 * j
 * 
 */

