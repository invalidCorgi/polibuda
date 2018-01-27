#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
    int fd1, size=0;
    
    for(int i=1;i<argc;i++){
        fd1 = open(argv[i], O_RDONLY);
        size = lseek(fd1, 0, SEEK_END);
        close(fd1);
        printf("%s has %d bytes\n",argv[i],size);
    }
    return 0;
}
