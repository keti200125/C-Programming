// Да се напише програма на С, която получава като параметри
// три команди (без параметри), изпълнява ги последователно,
// като изчаква края на всяка и извежда на стандартния изход
// номера на завършилия процес, както и неговия код на завършване

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <wait.h>

void executeCommand(const char* cmd, int* pid, int* status)
{
    if(fork())
    {
        *pid = wait(status);
    }
    else
    {
        if (execlp(cmd, cmd, "f1", NULL) == -1)
        {
            printf("Kid is trash");
            exit(-1);
        }
    }
}

int main(int argc, char **argv)
{
    if (argc < 4)
    {
        printf("error");
        exit(-1);
    }

    int pid;
    int status;
    executeCommand(argv[1], &pid, &status);
    printf("\npid: %d, status: %d \n", pid, status);
    executeCommand(argv[2], &pid, &status);
    printf("\npid: %d, status: %d \n", pid, status);
    executeCommand(argv[3], &pid, &status);
    printf("\npid: %d, status: %d \n", pid, status);
    
}