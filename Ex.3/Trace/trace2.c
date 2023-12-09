// Във файла ffff има следната информация I am a student!. Какво ще бъде
// изведено на стандартния изход и какво ще е съдържанието на файла ffff
// след успешното изпълнение на програмата /home/KN/SYSPROG/LAST/tras_2.

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    int fdi, fdo, k, broi, i = 0, status;
    char buff[40], c;
    if ((fdi = open("ffff", O_RDWR)) == -1)
    {
        printf("\n Cannot open \n");
        exit(1);
    }
    read(fdi, buff, 7);  // I am a(space) 
    write(1, buff, 7);   // I am a(space)
    write(1, "hap", 3);  // I am a hap
    write(fdi, "teacher", 7); //  fff: I am a teacher!
    write(1, "py child", 8); // I am happy child
}

// Output: I am happy child
// fff: I am a teacher!!!