#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
    //printf("%s",argv[1]);
    int fd1, fd2, n;
    char buf;

    fd1 = open(argv[1], O_RDONLY);
    fd2 = open(argv[2], O_CREAT | O_TRUNC | O_RDWR, 0644);

    while((n=read(fd1,&buf,1)) > 0)
    {
        write(fd2,&buf,n);
    }

    close(fd1);
    close(fd2);
    return 0;
}
