#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
    mkfifo("kulawy",0644);
    char buf[4096];
    int n;
    int fd = open("kulawy",O_RDONLY);
    while((n=read(fd,&buf,4096))>0)
        puts(buf);

    close(fd);
    
    return 0;
}
