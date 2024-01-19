// Ако в резултат на успешна компилация на зададения по-долу код на С е създаден изпълним файл с име progA
// и в текущата директория има текстов файл fileA.txt със съдържание
//     abc123-x
//     999aaa
//     yyyyyy6xxxxx
// напишете вдясно какво и къде ще се изведе,  в случай на успешното изпълнение  на progA  след стартиране с командния ред
// ./progA  fileA.txt  file1

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include<wait.h>
#include<unistd.h>

#include <stdio.h>
int main(int argc,char* argv[])
{
    int fd, fd1, i = 0;
    char c;
    if ((fd = open(argv[1], O_RDONLY)) == -1)
    {
        printf("\n Cannot open %s  ", argv[1]);
        exit(1);
    }
    if ((fd1 = open(argv[2], O_CREAT | O_TRUNC | O_RDWR, 0644)) == -1)
    {
        printf("\n Cannot open %s  ", argv[2]);
        exit(1);
    }

    while (read(fd, &c, 1)) 
    {
        ++i;
        if (c == '\n') // i=9
        {
            if (i < 10) //da
                for (i; i < 15; i++)
                {
                    write(1,"$", 1); // terminal: (6*$)
                    write(fd1,"#", 1); // file1: (6*#)
                }
            i = 0;
        }
        write(1, &c, 1); // abc123-x 
    }
    close(fd);
    close(fd1);
}

// terminal:
// abc123-x$$$$$$     
// 999aaa$$$$$$$$
// yyyyyy6xxxxx

// file:
// ##############

