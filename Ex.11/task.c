#include<unistd.h>


int main()
{
    int fd[2];
    // fd[0] ->read
    // fd[1] ->write
    if(pipe(fd)==-1)
    {
        perror("Pipe couldn't open");
    }
    //if you close fd of pipe in one process, in the orther is open
    int id=dork();
    if(id == 0)
    {
    }
    return 0;
}