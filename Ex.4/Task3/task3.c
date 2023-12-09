// В задача 2 се създава файл с име f1 и се пранасочва стандартния изход в него :
//   • чрез open
//   • чрез системен примитив dup

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{

    int fd = open(argv[1], O_WRONLY | O_CREAT, 0777);
    dup2(fd, 1);

    for (int i = 0; i < 10; i++)
    {
        write(1, "EXAMPLE ", 8);
    }

    close(fd);
}