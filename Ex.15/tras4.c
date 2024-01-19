// Напишете какво ще бъде изведено на стандартния изход (терминала),
// като резултат от изпълнението на файла, получен при успешна компилация на
// зададения по-долу програмен код на С, в който са използвани системни примитиви на ОС UNIX и LINUX:
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>

// a=500
// a=501
// a=2000
// print na failoevete v  tekushata direktoriq i info za tqh
// a=1002
// a=1003

int main()
{
    int a = 1000;

    if (fork()) //parent
    {
        a /= 2;
        printf("\nStoinostta na а = %d ", a);
    }
    else //child
    {
        if (fork())
        {
            a*= 2;
            printf("\nStoinostta na а = %d \n", a);
            if (execlp("ls", "ls", "-l", NULL) == -1) //end
            {
                a = a + 2;
                printf("\nStoinostta na a = %d ", a);
            }
        }
        else
        {
            a += 2;
            printf("\nStoinostta na а = %d ", a);
        }
    }
    a++;
    printf("\nStoinostta na a = %d ", a);
}
