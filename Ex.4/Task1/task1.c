//	Напишете програма на Си, която отваря файл за четене, дублира дескритора, последователно
// чете от двата дескриптора и извежда прочетеното на екрана. Затваря оригиналния дексриптор
//  и продължава за чете от дублирания.


// Ако сме изместил един fd, то местим и другите, създадени с dup дублажи
//Output: Hello, fr

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    int fd = open("f", O_RDONLY);
    if (fd == -1)
    {
        perror("File couldn't open");
        exit(-1);
    }

    int fd2 = dup(fd);
    if (fd2 == -1)
    {
        perror("File couldn't open");
        exit(-1);
    }

    char buff[10];

    read(fd, buff,4);
    write(1,buff,4);

    close(fd);

    read(fd2,buff,5);
    write(1,buff,5);
    
    close(fd2);
}
