// В текущия каталог се намира текстов файл abc със следното съдържание :
// Let’s go change the world!
// Напишете какво ще има записано във файла и какво ще бъде изведено на
// стандартния изход като резултат от изпълнението на дадения по-долу фмент от програма на С :

// Output: "Let's change the time! "
// abc: "Let’s go travel the world! "

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int fdi, fdio, nb1, nb2;
    char buff[15];
    fdi = open("abc", O_RDONLY);
    fdio = open("abc", O_RDWR);

    nb1 = read(fdi, buff, 6); // "Let’s "
    write(1, buff, nb1); // Terminal: "Let's "

    lseek(fdi, 3, SEEK_CUR); // Let’s go *pos*change the world!
    nb1 = read(fdi, buff, 6); // change
    write(1, buff, nb1); // Terminal: "Let's change"

    lseek(fdio, -18, SEEK_END); // "Let’s go *pos*change the world! "
    write(fdio, "tra", 3); // abc: "Let’s go trange the world! "

    write(fdio, "vel", 3); //abc: "Let’s go travel the world! "
    nb2 = read(fdio, buff, 5); // " the "
    write(1, buff, nb2);  // Terminal: "Let's change the "
    write(1, "time", 4);  // Terminal: "Let's change the time"

    lseek(fdi, -2, SEEK_END); //abc: "Let’s go travel the world*pos*! "
    nb2 = read(fdi, buff, 2); // "! "
    write(1, buff, nb2);  // Terminal: "Let's change the time! "
}
