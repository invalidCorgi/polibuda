#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
    int fd[2];
    pipe(fd);
    
    if(fork()==0)
    {
        close(fd[1]);
        dup2(fd[0],0);
        execl("/bin/tr","tr","a-z","A-Z",NULL);
        close(fd[0]);
        exit(1);
    }
    
    close(fd[0]);
    dup2(fd[1],1);
    execl("/bin/ls","ls",NULL);
    close(fd[1]);
    
    //return 0;
}
