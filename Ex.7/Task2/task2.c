// Да се пусне един fork() и само в детския процес още един fork(). За всеки
// генериран процес се отпечатва pid-а на процеса/getpid()/ и pid-a на родителския процес/getppid()/.

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <wait.h>

int main()
{
    printf("Starting from pid=%d\n", getpid());

    if (fork())
    {
        printf("\nGrandparent: My pid: %d, Parent pid: %d\n", getpid(), getppid());
    }
    else
    {
        printf("\nParent: My pid: %d, Parent pid: %d\n", getpid(), getppid());

        if (fork())
        {
            //printf("\nParent: My pid: %d, Parent pid: %d\n", getpid(), getppid());
        }
        else
        {
            printf("\nKid: My pid: %d, Parent pid: %d\n", getpid(), getppid());
        }
    }
}
