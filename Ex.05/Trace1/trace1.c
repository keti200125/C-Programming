// В текущия каталог се намира текстов файл ABC със следното съдържание:
// Let’s go light up the world!
// Напишете какво ще има записано във файла и какво ще бъде изведено на стандартния
// изход като резултат от изпълнението на дадения по-долу фрагмент от програма на С :

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

// Output: "Let’s light the sky! "
// abc: "Let’s go discover the world! "

int main()
{
    int fdi, fdio, nb1, nb2;
    char buff[15];
    fdi = open( "ABC", O_RDONLY);
    fdio = open( "ABC", O_RDWR);

    read(fdi, buff, 6); 
    write(1, buff, 6); // terminal: "Let’s "
    lseek(fdi, 3, SEEK_CUR); // 9 pos
    nb1 = read(fdi, buff, 6); 
    write(1, buff, nb1); // terminal: "light "

    lseek(fdio, -20, SEEK_END); // "Let’s go *pos*light up the world! "
    write(fdio,"disc", 4); //fdio:  "Let’s go disct up the world! "

    write(fdio,"over", 4);  //fdio:  "Let’s go discover the world! "
    nb2 = read(fdio, buff, 5); // discover*pos*
    write(1, buff, nb2); // terminal: " the "
    write(1,"sky", 3); // terminal: "sky"

    lseek(fdi, -2, SEEK_END); // *pos*!
    nb2 = read(fdi, buff, 2); // fdi: + "! "
    write(1, buff, nb2); //terminal: "! "
}
