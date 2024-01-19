// Да се напише програма на С, която използвайки системни примитиви
// за работа с файлове, чете последователност от символи от стандартния вход. 
// Добавя ги след края на файл ("keti"), чието име е подадено като първи параметър  
// /ако файла не съществува се създава/. Замества символите за табулация с  ‘ | -> ’ (7 char) 
// и резултата записва във файл, чието име е подадено като втори параметър
// /ако файл съществува – старото съдъжание се изтрива/.

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv)
{
    int fd=open(argv[1],O_RDWR|O_APPEND|O_CREAT,0777);
    int fd2=open(argv[2],O_WRONLY|O_CREAT,0777);
    if(fd==-1 || fd2==-1)
    {
        perror("File couldn't open");
        exit(-1);
    }

    char buff[2];

    while(read(0,buff,1)>0 && buff[0]!='\n')
    {
        write(fd,buff,1);
    }

    lseek(fd,0,SEEK_SET);

    while(read(fd,buff,1)>0)
    {
        if(buff[0]==' ')
        {
            write(fd2," | -> ",6);
        }
        else
        {
            write(fd2,buff,1);
        }
    }

    close(fd);
    close(fd2);
}

//ctr+D
