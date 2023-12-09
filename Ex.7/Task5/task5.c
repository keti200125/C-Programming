// Да се напише програма на С, която получава като параметри две
// имена на файлове. Отваря първия файл за писане (ако не съществува,
//  го създава, в противен случай го занулява), създава 2 процеса. 
// Родителят пише hello1, а детето – hello2 във първия файл. 

// не е много ясно условието


#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <wait.h>


int main(int argc,char** argv)
{
    if(argc<3)
    {
        printf("Parameters error");
        exit(-1);
    }
    
    int fd1=open(argv[1],O_WRONLY|O_CREAT|O_TRUNC,0777);
    if(fd1==-1)
    {
        perror("File couldn't open");
        exit(-1);
    }

    int pid=fork();

    if(pid==-1)
    {
        printf("error");
        exit(-1);
    }
    else if(pid==0)
    {
        write(fd1,"hello1",6);
    }
    else
    {
        write(fd1,"hello2",6);

    }


}
