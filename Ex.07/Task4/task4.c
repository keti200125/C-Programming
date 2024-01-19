// Да се създадат 2 процеса. В детския се пише Hello на стандартния
// изход. След това се създават още 2  процеса и се пише Hello1 на
// стандартния изход. Колко пъти излиза Hello и колко Hello1?

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <wait.h>

//4

int main()
{
    if (fork())
    {
    }
    else
    {
        write(1, "Hello ", 6);
        fork();
        fork();
        write(1, "Hello1 ", 7);
    }
}
