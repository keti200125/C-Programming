// Какво ще бъде изведено на стандартиня изход след успешното изпълнение на програмата /home/KN/SYSPROG/LAST/tras_1.

#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>

int main(int argc, char *argv[])
{
    int fd, fd1, broi;
    char buff[15] = "";
    fd1 = open("x1", O_CREAT | O_TRUNC | O_RDWR, 0666);
    write(fd1, "I am a student Computer science!!!", 34); // x1: "I am a student Computer science!!!
    lseek(fd1, 0, 0);                                     // fd1 -> I (first character)
    while ((broi = read(fd1, buff, 10)) != 0)
    {
        write(1, buff, broi); // I am stu // dent Compu // ter scienc // e!!!
        write(1, "ECHO", 4);  // I am stuECHO //dent CompuECHO // ter sciencECHO // e!!!ECHO
        printf("\n%d\n", broi); // 10 // 10
    }                      
    printf("\n%d\n", broi); 
}

// I am stuECHO
// 10
// dent CompuECHO
// 10
// ter sciencECHO
// 10
// e!!!ECHO
// 4
//
// 0
