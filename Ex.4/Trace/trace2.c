#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Ако сме изместил един fd, то местим и другите, създадени с dup дублажи

// Output: 
// keti25.0225
// 25.0225.02

int main(int argc, char *argv[]) {
  int fd, j, nb1;
  char buff[5];

  j = dup(1);  // j -> STDOUT
  fd = open("fileA", O_RDWR); 

  nb1 = read(0, buff, 4); // read 4 elems form STDIN: example: keti
  write(j, buff, nb1); // write them on the STDOUT // keti

  nb1 = read(fd, buff, 5); // read 5 from fileA // 25.02
  write(1, buff, nb1); // write them on STDOUT // 25.02
  write(fd, buff, nb1); // + write them in fileA // 25.0225.02
  write(j, buff, 3);  // write on stdout // 25.

  close(fd);
  close(j);
  write(1, "\n", 1); //new line
  execlp("cat", "cat", "fileA", NULL); //print fileA
}