// Да се състави програма на Си, която получава два параметъра, първият
// от които е име на съществуващ текстов файл, в който дължината на редовете
// не надвишава 60. Програмата извежда на стандартния изход онези от редове от
// текстовия файл, чийто последен символ е $. Създава файл с име втория параметър
// и в него записва - всеки път на нов ред – само цифрите, от всеки от останалите
// редове от първия файл. Извежда броя на редовете от новосформирания файл.

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char **argv)
{
    char buf[62];
    int characters = 0;
    bool hasCharacter = false;

    int fd1 = open(argv[1], O_RDONLY);
    if (fd1 == -1)
    {
        perror("file couldn't open");
        exit(-1);
    }

    while (read(fd1, buf, 1) > 0)
    {
        characters++;
    
        if (buf[0] == '\n' && hasCharacter)
        {
            lseek(fd1, -characters, SEEK_CUR);
            int r=read(fd1,buf,characters);
            write(1,buf,r);
            characters = 0;
        }
        else if(buf[0]=='\n' && !hasCharacter)
        {
            characters=0;
        }

        if (buf[0] == '$')
            hasCharacter = true;
        else
            hasCharacter = false;
    }

    close(fd1);
}