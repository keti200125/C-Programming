//  Да се пуснат три fork() един след друг. Колко процеса се генерират?


#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <wait.h>
#include <sys/mman.h>



int main()
{
    int* shmem = (int*)mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE,  MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    forkOnce();
    forkOnce();
    forkOnce();

    (*shmem)++;

    printf("%d ",*shmem);

    forkOnce();


    forkOnce();
}