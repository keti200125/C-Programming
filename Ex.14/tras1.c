// В текущия каталог се намира текстов файл fileB със следното съдържание
//   аbcdef
//   0123456789
//   ABCD
// Изпълнимия файл,получен след компилация на зададения по - долу програмен фрагмент
// се стартира с командния ред :./ a.out f2
// Напишете какво ще бъде изведено на стандартния изход и какво ще бъде съдържанието
// на двата файла след приключване на успешното изпълнение

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int fdi, fdo, k, broi, i = 0, status;
    char buff[40], c;
    if ((fdi = open("fileB.txt", O_RDWR)) == -1)
    {
        printf("\n Cannot open  \n");
        exit(1);
    }
    if ((fdo = open(argv[1], O_CREAT | O_TRUNC | O_RDWR, 0666)) == -1)
    {
        printf("\n Cannot open  \n");
        exit(1);
    }

    if (fork() == 0)
    {
        k = dup(1); // дублира файлов дескриптор, чрез k можем да пишем на терминала 
        close(1); // затваряме фд за писане на терминала 
        dup(fdi);                   // сега когато пишем на 1, ще пишем във файла fileB
        broi = read(fdi, buff, 40); // buff = fileB
        c = buff[i++];              // c = a
        if (c <= '0' || c >= '9') //'a' > '9'
        {
            while (buff[i++] != '\n' && i < broi)  // broi=22,i=1
                write(1, "*", 1); // ***** in fileB (beginning)
            write(1, "\n", 1); // new Line
            close(1);  
            dup(k); // 1 otnovo e terminala
            write(1, "*\n", 2); // terminal: * and new line
        }
        else
        {
            write(1, buff, broi); //
            close(1);
            dup(k);            // 
            write(1, "\n", 1);
        }
        write(fdo, buff, 7); // fdo: abcdf\n
        write(fdo, "*\n", 2); // fdo: abcdef\n*\n
        close(fdi); 
        close(fdo);
    }
    else
    {
        wait(&status);
        close(1);
        dup(fdi);
        execlp("grep", "grep", "c", argv[1], NULL); // fileB:   abcdef\n*\n
        execlp("wc", "wc", "-l",argv[1], NULL); // nothing
    }
}
