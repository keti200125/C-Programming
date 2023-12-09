// Напишете програма на Си, която печата симолния низ „EXAMPLE“
// и символния низ  „HELLO“ 10 пъти на стандартния изход, 
// като между тях се извеждат числата от 1 до 10.

#include <unistd.h>
#include <fcntl.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
    for (int i = 1; i < 11; i++)
    {
        printf("%s","EXAMPLE ");
        printf(" %d ",i);
        printf("%s\n","HELLO ");
    }

}

