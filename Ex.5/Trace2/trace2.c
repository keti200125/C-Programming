// В текущия каталог се намира текстов файл ABC. Като първи параметър
// на програма на С се подава съществуващ празен файл. Напишете какво ще
// има записано във файла и какво ще бъде изведено на стандартния изход като
// резултат от изпълнението на дадения по-долу фрагмент от програма на С :

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <wait.h>

// Output:   // File:
// cat       // test2
// test2     // test3
// test3

int main(int argc, char *argv[])
{
    int fd, i, status;
    if (fork()) // if is the parent
    {
        wait(&status); // wait for kid
        for (i = 0; i <= 4; i++)
        {
            write(1, "cat\n", 4);
            execlp("cat", "cat", "ABC", NULL);
            write(1, "test1\n", 6);
        }
    }
    else
    {
        close(1);                   // close STDOOT
        fd = open(argv[1], O_RDWR); // open ABC, fd=1
        write(1, "test2\n", 6);     //  ABC: test2\n 
    }
    write(1, "test3\n", 6); // ABC: test2\n test3\n
}
