// Напишете програма на Си, която печата символния низ „EXAMPLE“ 10 пъти на стандартния изход.

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    for (int i = 0; i < 10; i++)
    {
        write(1, "EXAMPLE ", 8);
    }
}