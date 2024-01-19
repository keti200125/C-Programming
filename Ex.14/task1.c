// Да се състави програма на Си, която ползвайки системните промотиви за работа с
// файлове и процеси в LINUX, получава като аргуманти в командния ред при стартиране
// два символни низа(имена на файлове).

// Програмата стартира нов /детски процес/, в рамките на който четейки
// символ по символ от файла на стандартния вход до достигане на края му,
// копира през един прочитаните редове в новосъздадения файл с име зададения като първи аргумент низ,
// започвайки от втория ред, като заменя всяка буква със символа ‘*‘.

// В рамките на родителския процес, пренасочвайки стандартния изход във файла с име,
// зададено като втори аргумент, пресмята и извежда, всеки път на отделен ред, дължините на редовете от първия файл

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <wait.h>
int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        perror("Not enough parameters");
        exit(1);
    }
    int fd1 = open(argv[1], O_CREAT | O_RDWR | O_TRUNC, 0777);
    int fd2 = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0777);
    int fd3 = open("INPUT.txt", O_RDONLY);

    if (fd1 == -1 || fd2 == -1)
    {
        perror("open problem");
        exit(1);
    }

    close(0);
    dup(fd3);
    close(fd3);
    int id;

    if ((id = fork())) // parent
    {
        char c;
        int status;
        waitpid(id, &status, 0);
        close(1);
        dup(fd2);
        close(fd2);
        int count = 0;

        lseek(fd1, 0, SEEK_SET); // важно е да се направи понеже fd се споделят между процесите (fd1,0,0)
        while (read(fd1, &c, 1) > 0)
        {
            if (c == '\n')
            {
                printf("%d\n", count);
                count = 0;
            }
            else
            {
                count++;
            }
        }
        printf("%d\n", count);
    }
    else // kid
    {

        bool isEvenLine = false;
        char c;
        while (read(0, &c, 1) > 0)
        {
            if (c == '\n')
            {
                if (isEvenLine)
                {
                    write(fd1, "\n", 1);
                    isEvenLine = false;
                }
                else
                {
                    isEvenLine = true;
                }
            }
            else
            {
                if (isEvenLine)
                {
                    if (c >= 'a' && c <= 'z')
                    {
                        write(fd1, "*", 1);
                    }
                    else
                    {
                        write(fd1, &c, 1);
                    }
                }
            }
        }
    }
}