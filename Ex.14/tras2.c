// Напишете какво ще бъде изведено на стандартния изход (терминала),  като резултат
// от изпълнението на файла, получен при успешна компилация на зададения по-долу програмен код
// на С, в който са използвани системни примитиви на ОС UNIX и LINUX:

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    int a = 2000;

    if (fork()) // parent
    {
        a /= 2; 
        printf("\nStoinostta na a = %d ", a); // a=1000
    }
    else
    {
        if (fork())
        {
            a *= 2; // 4000
            printf("\nStoinostta na a = %d ", a); //a =4000

            if (execlp("ps","ps", "-u","keti", NULL) == -1) // information of the processes that are currently working
            {
                a = a + 2; 
                printf("\nStoinostta na a = %d ", a);
            }
        }
        else
        {
            a += 2;
            printf("\nStoinostta na a = %d", a); // a = 2002
        }
    }
    a++; 
    printf("\nStoinostta na a = %d ", a); // a=1001 a=2003
}


// Stoinostta na a = 1000
// Stoinostta na a = 1001
// Stoinostta na = 4000 ????????
// info of currently working processes
// Stoinostta na a = 2002
// Stoinostta na a = 2003

