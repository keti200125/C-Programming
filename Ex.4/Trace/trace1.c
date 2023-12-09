#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<wait.h>

//Output:
// a= 0
// b= 3
// a= 9
// b= 1 

int main(int argc, char *argv[])
{
    int b = 1, a = 5, status; 
    char buff[2];

    int pid = fork(); 
    if (pid == 0) //child
    {
        b = 3;
        a = 0;
    }
    else
    {
        a = 9;
        wait(&status); //wait for child
    }

    write(1, "\n a= ", 5);  // a=  //a=
    sprintf(buff, "%d", a); //  buf: 0  // buf: 9
    write(1, buff, sizeof(buff)); // 0  // 9

    write(1, "\n b= ", 5); // b=  //b=
    sprintf(buff, "%d", b); // buf: 3  // buf: 1
    write(1, buff, sizeof(buff)); // 3  //1
}