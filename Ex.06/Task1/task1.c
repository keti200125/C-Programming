// Напишете програма на Си, която изпълнява команда
// извеждаща редовете, в които се среща символния низ 
// int в подадения като параметър файл.

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>



int main(int argc,char** argv)
{
    execlp("grep","grep","int","int.txt",NULL);
}