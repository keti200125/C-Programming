// Да се пуснат един след друг два системни примитива fork(), като за
// всеки генериран процес се отпечатва pid-а на процеса/getpid()/ и
// pid-a на родителския процес/getppid()/.


#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <wait.h>

int main()
{
    if(fork())
    {
        printf("\n Curr parent: Kid pid: %d, Parent pid: %d\n",getpid(),getppid());

    }
    else
    {
         printf("\n Curr kid: Kid pid: %d, Parent pid: %d\n",getpid(),getppid());

    }
}