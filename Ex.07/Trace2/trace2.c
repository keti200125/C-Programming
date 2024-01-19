
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <wait.h>
#define CMD "who"

//Output: 
// exam2
// I=3, K=1
// keti     pts/1        2023-11-27 15:11
// keti     pts/6        2023-11-27 15:44 (tmux(6281).%0)
// exam1
// I=1 K= -1
// exam4
// a.out trace2.c

int main()
{
    int fd, i = 2, k = 0, status;
    if (fork()) //if parent 
    {
        wait(&status); //wait
        i--; //i=1
        k--; // k=0
        write(1, "exam1\n", 6); // Terminal: exam1
        printf("I=%d K= %d \n", i, k); // I=1 k=-1\n
    }
    else
    {
        for (k = 1; k <= 3; k++)
        {
            write(1, "exam2\n", 6); //Terminal: "exam2\n"
            i = k + i;              // i= 1+2 =3
            printf("I=%d K=%d\n", i, k); // Terminal: I=3, K=1\n
            if ((execlp(CMD, CMD, NULL)) == -1)   // 
                write(1, "exam3\n", 6); 
            printf("I=%d K=%d\n", i, k);
        }
    }
    write(1, "exam4\n", 6); //Terminal: exam4\n
    if ((execlp("ls", "ls", NULL )) == -1) 
        printf("I=%d K=%d\n", i, k); 
    else
    {
        write(1, "exam5\n", 6);
    }
}
