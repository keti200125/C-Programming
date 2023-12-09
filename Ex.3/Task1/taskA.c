// Напишете програма, която създава файла fff и го отваря три пъти:
// само за четене през fd1
// само за писане през fd2
// за четене и писане през fd3
// След това:
// A)
// през fd2 записва “Hello world” в него 
// през fd3 прочита 6 байта и изписва прочетеното на стандартния изход 
// през fd1 прочита 5 байта и изписва прочетеното на стандартния изход
// през fd3 записва “chil” в него 
// през fd2 записва “!!!” в него
// през fd1 прочита 9 байта и изписва прочетеното на стандартния изход

//всеки файлов дескриптор се движи самостоятелно по файла 
//изход: Hello Hello child!!!

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int fd1 = open("fff.txt", O_RDONLY | O_CREAT|O_TRUNC, 0644);
    int fd2 = open("fff.txt", O_WRONLY);
    int fd3 = open("fff.txt", O_RDWR);

    if (fd1 == -1 || fd2 == -1 || fd3 == -1)
    {
        perror("File couldn't open");
        exit(-1);
    }

    char buf[12];

    write(fd2, "Hello world", 11); // fff: Hello world

    int r = read(fd3, buf, 6);
    write(1, buf, r);

    int r2 = read(fd1, buf, 5);
    write(1, buf, r2);

    write(fd3, "chil", 4); // fff: Hello child
    write(fd2, "!!!", 3); // fff: Hello child!!!

    int r3 = read(fd1, buf, 9); //start form 7th pos: child!!!
    write(1, buf, r3);

    close(fd1);
    close(fd2);
    close(fd3);
}