// Да се напише програма на С, която получава като параметър име
// на файл. Отваря подадения файл за писане (ако не съществува, го
// създава, в противен случай го занулява), създава 2 процеса и двата
// процеса пишат символния низ Hello във файла.
//           •	файла се отваря с 2 различни дескриптора.

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <wait.h>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("error");
        exit(-1);
    }

    int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    int fd2 = open(argv[1], O_WRONLY);
    if (fd == -1||fd2==-1)
    {
        printf("open err\n");
        exit(1);
    }

    int id=fork();

    if(id==-1)
    {
        printf("Error");
        exit(-1);
    }
    else if(id==0)
    {
        write(fd,"Hello",5);
    }
    else
    {
        write(fd2,"Hello",5);
    }
}