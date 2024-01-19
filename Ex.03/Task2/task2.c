// В текущата директория се намира файл f1 със съдържание:
// abcd-abcd-abcd
// Отворете файла с 2 различни дескриптора за четене и писане. 
// Започвайки от последните 2 символа напишете думата wxyz.
// Запишете върху 5 и 6-тия символ от началото на файла - цифрите 1 и 2. 
// Отпечатайте цялото съдържание на файла.

//Output
// Ако искаме да достигнем позиция 5 от SEEK_SET, offset е 4


#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int fdRead=open("f1.txt",O_RDONLY);
    int fdWrite=open("f1.txt",O_WRONLY);

    if(fdRead==-1 || fdWrite==-1)
    {
        perror("File couldn't open");
        exit(-1);
    }

    lseek(fdWrite,-2,SEEK_END); // abcd-abcd-abwxyz
    write(fdWrite,"wxyz",4);

    lseek(fdWrite,4,SEEK_SET); // abcd-abcd-abwxyz
    write(fdWrite,"12",2);

    char buf[30];

    int r=read(fdRead,buf,30);
    write(1,buf,r);

    close(fdRead);
    close(fdWrite);
    
}