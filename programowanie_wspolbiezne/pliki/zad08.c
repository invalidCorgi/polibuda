#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
    int n, fd;
    char buf[4096];
    
    if(argc==2)
        fd = open(argv[1],O_RDONLY);
    else
        fd = 0;
    
    while((n=read(fd,buf,4096))>0){
        for(int i=0;i<=n;i++)
            if(buf[i]>=97 && buf[i]<=122)
                buf[i]-=32;
        write(1,buf,n);
    }
    
    return 0;
}
