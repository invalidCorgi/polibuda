#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
    char *str = "kulawy";
    mkfifo("kulawy",0644);
    int fd = open("kulawy",O_WRONLY);
    write(fd,str,7);
    close(fd);
    
    return 0;
}
