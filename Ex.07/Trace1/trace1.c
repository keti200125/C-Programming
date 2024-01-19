#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

// not ok

int main()
{
    int fd, k, nb;
    char buf[6];

    k = dup(0); // k->STDIN
    fd = open("fileB", O_RDWR);
    nb = read(k, buf, 5); 
    write(fd, buf, nb); 
    lseek(fd, 3, SEEK_CUR); 
    write(1, buf, nb);      
    nb = read(0, buf, 4);   
    write(1, buf, nb);     
    close(fd);
    close(k);
    write(1, "\n", 1);
    execlp("cat", "cat", "fileB", 0);  
}
