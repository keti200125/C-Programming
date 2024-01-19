#include    <stdio.h>
#include    <stdlib.h>
#include    <unistd.h>
#include    <fcntl.h>
#include    <string.h>


int main()
{
     // създава/отваря_съществуващ файл;
    int fd = open("file.txt",O_RDWR|O_CREAT|O_TRUNC,0777);
    if(fd==-1)
    {
        perror("File couldn't open");
        exit(1);
    }
    //инициализира/записва в началото му
    // начална числова стойност (примерно 0);
    int n=0;
    char buff[20];
    write(fd,&n,sizeof(int));
 
    // стартира нов процес (примитив fork)
    int pid=fork();

    if(pid==-1)
    {
        perror("Couldn't fork");
        exit(1);
    }
    else if(pid==0)
    {
        for(int i=0;i<50;i++)
        {
            // позициониране на едно и също място във файла (началото)
            lseek(fd,0,SEEK_SET); // fd,0,0
            // прочитане на целочислена стойност
            read(fd,&n,sizeof(int));
            // модифициране на стойността (добавяне константна стойност – 1 или 2)
            n+=1;
            // извеждане на модифицираната стойност на стандартния изход
            // int to str
            sprintf(buff, "\t\tChild: %d\n",n);
            write(1,&buff,strlen(buff));
             // позициониране на същото място (началото)
            lseek(fd,SEEK_SET,0);
            // запис на модифицираната стойност на мястото на прочетената.
            write(fd,&n,sizeof(int));
        }
    }
    else
    {
        for(int i=0;i<100;i++)
        {
            // позициониране на едно и също място във файла (началото)
            lseek(fd,0,SEEK_SET); // fd,0,0
            // прочитане на целочислена стойност
            read(fd,&n,sizeof(int));
            // модифициране на стойността (добавяне константна стойност – 1 или 2)
            n+=2;
            // извеждане на модифицираната стойност на стандартния изход
            //int to str
            sprintf(buff, "\t\tParent: %d\n",n);
            write(1,&buff,strlen(buff));
            // позициониране на същото място (началото)
            lseek(fd,SEEK_SET,0);
            // запис на модифицираната стойност на мястото на прочетената.
            write(fd,&n,sizeof(int));


        }

    }

    lseek(fd, SEEK_SET, 0);
    read(fd, &n, sizeof(int));
    sprintf(buff, "\n Final val: %d\n", n);
    write(1, buff, strlen(buff));

}