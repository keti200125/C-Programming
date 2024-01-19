/*В текущия каталог се намира текстов файл fileD.txt със следното съдържание
    123456789
    $$abcdefg
Напишете вдясно какво ще бъде изведено на стандартния изход (терминала)и какво ще бъде
съдържанието на новосъздадения фаил,  като резултат от изпълнението на файла, получен
при успешна компилация на зададения по-долу програмен код на С, в който са използвани
системни примитиви на ОС UNIX и LINUX:*/
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>
int main()
{
    int fdr, fdw, n_byt, i = 0, status;
    char symbols[40], c;
    if (fork())
    {
        wait(&status);
        if (open("file_new", O_RDONLY) != -1) // it is already open :) 
        {
            write(1, "\n", 1);
            execlp("wc", "wc", "-c", "file_new", NULL); // character in file_new an it name
            execlp("head", "head", "-5c", "file_new", NULL);
        }
    }
    else // in the kid
    {
        if ((fdr = open("fileD.txt", O_RDONLY)) == -1)
        {
            printf("\n Cannot open  \n");
            exit(1);
        }
        if ((fdw = open("file_new", O_CREAT | O_TRUNC | O_RDWR, 0666)) == -1)
        {
            printf("\n Cannot creat  \n");
            exit(1);
        }
        n_byt = read(fdr, symbols, 40);
         // 123456789
         // $$abcdefg ->19
        c = symbols[i++]; //1, i=1
        if (c >= '0' && c <= '9') // yes
        {

            while (symbols[i++] != '\n' && i < n_byt) // 
                write(fdw, "$", 1); // file_new: $*8
            write(fdw, "\n", 1); // file_new: $*18\n
            write(1, "\n", 1); //terminal: \n
        }
        else
        {
            write(1, symbols, n_byt);
            write(1, "\n", 1);
        }
        write(fdw, "$\n", 2); // file_new: $*18\n$\n
        write(1, symbols, 12); // terminal 123456789\n$$
        close(fdr);
        close(fdw);
    }
}

//file new:
// $$$$$$$$
// $

//terminal:
// 
// 123456789
// $$
// 11 file_new
