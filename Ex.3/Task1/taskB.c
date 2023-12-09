// Напишете програма, която създава файла fff и го отваря три пъти:
// само за четене през fd1
// само за писане през fd2
// за четене и писане през fd3
// След това:
// Б)
// през fd3 записва “Hello” в него
// през fd2 записва „worlds” в него
// през fd1 прочита 6 байта и изписва прочетеното на стандартния изход
// затваря fd2
// през fd3 записва “oops” в него
// през fd1 прочита 6 байта и изписва прочетеното на стандартния изход

// output: worldops


#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int fd1 = open("ff.txt", O_RDONLY | O_CREAT, 0777);
    int fd2 = open("ff.txt", O_WRONLY);
    int fd3 = open("ff.txt", O_RDWR);

    if (fd1 == -1 || fd2 == -1 || fd3 == -1)
    {
        perror("File couldn't open");
        exit(-1);
    }

    char buf[12];
    char buf2[10];

    write(fd3, "Hello", 5); // ff: Hello

    write(fd2,"worlds",6); // ff: worlds

    read(fd1, buf, 6);
    write(1, buf, 6);

    close(fd2);

    write(fd3,"oops",4); // ff: worldoops

    read(fd1, buf2, 6);  // 7th position ops  
    write(1, buf2, 6);

    close(fd1);
    close(fd3);
}
