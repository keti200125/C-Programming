//Първата задача, като преди всяко read се слага системен примитив lseek.
//	1)   lseek(fd, 0 , 0)
//     2)	lseek( fd, 3, 0)
//     3)	lseek( fd, 3, SEEK_CUR)
//     4)	lseek( fd, -3, SEEK_END) и други варианти

#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
    int fd=open("aa.txt",O_RDONLY);
    if(fd==-1)
    {
        perror("File couldn't open");
        exit(-1);
    }

    char buf[16];

    for(int i=5;i>0;i--)
    {
        //lseek(fd,0,SEEK_SET);
        //lseek(fd,3,0);
        //lseek(fd,3,SEEK_CUR);
        lseek(fd,-3,SEEK_END);
        read(fd,buf,i);
        write(1,buf,i);
        write(1,"\n",1);
    }
}