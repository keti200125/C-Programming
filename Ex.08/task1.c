// Да се напише програма на C, която получава като параметри от команден
// ред две команди (без параметри) и име на файл в текущата директория.
// Ако файлът не съществува, го създава. Програмата изпълнява командите
// последователно, по реда на подаването им. Ако първата команда завърши
// успешно, програмата добавя нейното име към съдържанието на файла, подаден
// като команден параметър. Ако командата завърши неуспешно, програмата уведомява
// потребителя чрез подходящо съобщение.

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Not enough parameters");
        exit(1);
    }

    int fd = open(argv[3], O_WRONLY | O_CREAT, 0777);
    if (fd == -1)
    {
        perror("File couldn't open");
        exit(1);
    }

    int status;

    if (fork() == 0)
    {
        if (fork() == 0)
        {
            execlp(argv[1], argv[1], NULL);
            exit(1);
        }
        else
        {
            wait(&status);
            if (status == 0)
            {
                write(fd, argv[1], strlen(argv[1]));
            }
            else
            {
                write(2, "ERROR: execution unsuccessful\n", sizeof("ERROR: execution unsuccessful\n"));
            }
        }

        execlp(argv[2], argv[2], NULL);
        exit(1);
    }
    else
    {
        wait(&status);
        if (status == 0)
        {
            write(fd, " ", 1);
            write(fd, argv[2], strlen(argv[2]));
            exit(1);
        }
        else
        {
            write(2, "ERROR: execution unsuccessful\n", sizeof("ERROR: execution unsuccessful\n"));
        }
    }

    close(fd);
}