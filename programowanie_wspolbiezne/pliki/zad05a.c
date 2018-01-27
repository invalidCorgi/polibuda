#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

void readAndWriteOneChar(int fd1){
    char temp;
    read(fd1,&temp,1);
    write(0,&temp,1);
}

int main(int argc, char* argv[])
{
    int fd1;
    
    fd1 = open(argv[1], O_RDONLY);
    lseek(fd1, -1, SEEK_END);
    readAndWriteOneChar(fd1);
    
    while(lseek(fd1,-2,SEEK_CUR)){
        readAndWriteOneChar(fd1);
    }
    
    readAndWriteOneChar(fd1);
    puts("");
    
    return 0;
}
