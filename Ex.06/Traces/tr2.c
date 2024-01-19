#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <wait.h>

int main()
{
    int pid, status;
    char c = '0', d = 'b';

    pid = fork(); 
    if (pid != 0) //parent
    {
        c = '2';
        wait(&status); //wait for kid
    }
    else
    {
        d = 'z';
        write(1, "\n c= ", 5); // c= 
        write(1, &c, 1);       // 0
    }

    write(1, "\n d= ", 5); // d= 
    write(1, &d, 1);       // z
}

/*
 *
 * Output:
 *
 * c= 0
 * d= z
 * d= b
 *
 */