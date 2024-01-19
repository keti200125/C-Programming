// Напишете програма на Си, която получава като аргумент два файла. 
// Чете от първия файл и извежда във втория чрез механизма на
// пренасочване на стандартния вход и изход

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char** argv)
{
    if(argc<3)
    {
        printf("No arguments");
        exit(-1);
    }
        
    int fd1=open(argv[1],O_RDONLY);
    if(fd1==-1)
    {
        perror("File couldn't open");
        exit(-1);
    }

    int fd2=open(argv[2],O_WRONLY|O_CREAT,0777);
    if(fd2==-1)
    {
        perror("File couldn't open");
        exit(-1);
    }

    dup2(fd2,1);
    dup2(fd1,0);
    char buff[5];
    int r;

    while((r=read(0,buff,5))>0)
    {
        write(1,buff,r);
    }

    close(fd1);
    close(fd2);
}
