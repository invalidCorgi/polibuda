#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <wait.h>

int main(int argc, char* argv[])
{
    mkfifo("kulawy",0644);
    
    if(fork()!=0)
    {
        int fd = open("kulawy",O_RDONLY);
        dup2(fd,0);
        execl("/bin/wc","wc",NULL);
        close(fd);
        exit(1);
    }
    
    int fd = open("kulawy",O_WRONLY);
    dup2(fd,1);
    execl("/bin/ls","ls",NULL);
    close(fd);
    
    return 0;
}
