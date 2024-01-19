#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include<wait.h>
#include<unistd.h>


int main(int args, char *argv[])
{
    int fdr, fdw, n_byt, i = 0, status;
    char symbols[40], c;
    if (fork())
    {
        wait(&status);
        if (open("file_second", O_RDONLY) != -1) 
            write(1, "\n", 1);
        execlp("grep", "grep", "234", "file_second", NULL); 
        execlp("wc", "wc", "-l", "file_second", NULL);
    }
    else  // in the kid
    {
        if ((fdr = open("file_first.txt", O_RDONLY)) == -1)  // open file_first for read
        {
            printf("\n Cannot open \n");
            exit(1);
        }
        if ((fdw = open("file_second", O_CREAT | O_TRUNC | O_RDWR, 0666)) == -1) // open file_secon for read and every timr write delete wht is in 
        {
            printf("\n Cannot open \n");
            exit(1);
        }
        n_byt = read(fdr, symbols, 22); // read 22 bytes from fdr  symbols: 123456789\nAABBCCDDE
        write(fdw, "12345\n", 6); // file_second: 12345\n 
        c = symbols[i++];  //i =1 , c= "1" 
        if (c >= '0' && c <= '9')
        {
            while (symbols[i++] != '\n' && i < n_byt) 23456789
                write(fdw, "12345", 5);      // file_second: 12345\n((12345*8))
            write(fdw, "\n", 1);             // file_second: 12345\n((12345*8))\n
            write(1, "AAA\n", 4);            // terminal: AAA
        }
        else // ne vlizame tuk
        {
            write(1, symbols, n_byt);
            write(fdw, symbols, 8);  
            write(1, "\n", 1);       
        }
        write(fdw, "AAA\n", 4); // file_second: 12345\n((12345*8))\nAAA 
        write(1, symbols, 12);  // terminal: 123456789\nAA
        close(fdr);            
        close(fdw);
    }
}


// AAA
// 123456789
// AA
// 12345
// 1234512345123451234512345123451234512345