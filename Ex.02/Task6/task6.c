// Записват се във файл 25 байта извън програмата. Програмата чете от файла по 10 байта  и отпечатава какво връща състемния примитив read


#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{

    int fd=open("25.txt",O_RDWR|O_CREAT|O_APPEND,777);
    if(fd==-1)
    {
        perror("File couldn't open");
        exit(-1);
    }

    char buf[11];

    int bytes;

    while((bytes=read(fd,buf,10))>0)
    {
        printf("%d\n",bytes); //%d - Take the next argument and print it as an int
        write(1,buf,bytes);
        write(1,"\n",1);
    }

    close(fd);

}