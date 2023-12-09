// В зад 1 – напишете грешна команда.

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>



int main(int argc,char** argv)
{
    if(argc<2)
    {
        printf("Not enough arguments");
        exit(-1);
    }

    if(execlp("prep","prep","int","int.txt",NULL)==-1)
    {
        printf("Mistake in the command");
        exit(-1);
    }
}