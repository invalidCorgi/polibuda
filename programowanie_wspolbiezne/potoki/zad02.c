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
        int n;
        char buf;
        while((n=read(fd[0],&buf,1))>0)
        {
            printf("%c",buf);
        }
        printf("\n");
        close(fd[0]);
        exit(1);
    }
    
    if(fork()==0)
    {
        close(fd[0]);
        char* kulawy = "kulawy chuj";
        write(fd[1],kulawy,11);
        close(fd[1]);
        exit(1);
    }
    
    return 0;
}
