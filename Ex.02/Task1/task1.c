
// Създайте файл aa със съдържание английската азбука - извън програмата.
// Задачата отваря файла aa само за четене. Чете от него чрез цикъл for и
// променлива в диапазон  от 5 до 1 в буфер с размер 16 байта. Отпечатва
// с printf съдържанието на  буфера на всяка итерация.

#include <fcntl.h>  //open
#include <unistd.h> //read
#include <stdio.h>  //print
#include <stdlib.h> //exit(-1)

int main()
{
    int fd = open("aa.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("File couldn't open");
        exit(-1);
    }

    char buf[16];
    int i;
    for (i = 5; i > 0; i--)
    {
        read(fd, buf, i);
        printf("%s\n", buf); //print for strings
    }

    close(fd);
}

/*
 *
 * Output:
 *
 * abcde
 * fghie
 * jklie
 * mnlie
 * onlie
 *
*/