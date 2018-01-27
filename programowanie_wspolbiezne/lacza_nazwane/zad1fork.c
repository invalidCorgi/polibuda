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
    
    if(fork()==0)
    {
        char buf[4096];
        int n;
        int fd = open("kulawy",O_RDONLY);
        while((n=read(fd,&buf,4096))>0){
            puts(buf);
        }
        
        exit(1);
    }
    
    int fd = open("kulawy",O_WRONLY);
    write(fd,str,7);
    close(fd);
    
    return 0;
}
