// задача 1, като вместо printf използва системен примитив write и извежда на стандартния изход.

#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
    int fd=open(argv[1],O_RDONLY);
    if(fd==-1)
    {
        perror("File couldn't open");
        exit(-1);
    }

    char buf[16];

    for(int i=5;i>0;i--)
    {
        read(fd,buf,i);
        write(1,buf,i);
        write(1,"\n",1);
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