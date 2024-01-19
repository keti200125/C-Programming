#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
// Да се наpише програма на Си, която прави канал между 2 команди в явен вид. Примерно who | wc –l


int main()
{
    int fd[2]; 
    if(pipe(fd)==-1)
    {
        perror("Pipe couldn't open");
        exit(1);
    }
    // fd[0] -> read
    // fd[1] -> write
    int id = fork();
    if(id==-1)
    {
        perror("Couldn't fork");
        exit(1);
    }
    else if(id ==0)
    {
        close(fd[0]); // затваряме канала за четене 
        close(1); // who ще се изпринти на stdout а ние искаме в тръбата,затваряме го
        dup(fd[1]);  // вече резултатът от exec с who ще се *запише* в тръбата не на stdout
        //dup2(fd[1],1); вместо close и dup
        close(fd[1]);  // не трябва да има повече от 1 fd за всеки край на тръбата
        execlp("who","who",NULL);

    }
    else
    {
        close(fd[1]); // в родителя няма да пишем нищо в тръбата, а само ще четем от нея
        close(0); // тъй като wc -l взима данни от stdin, а ние искаме от тръбата, то трябва да го сменим
        dup(fd[0]); // слагаме стандартният вход да е fd[0], оттам да четем
        close(fd[0]); // не трябва да има повече от 1 fd за всеки край на тръбата
        execlp("wc", "wc", "-l", NULL); // execute 'wc' reading from pipe read fd
    }

}