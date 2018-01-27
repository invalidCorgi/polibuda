#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
    int fileToSave, fd,n;
    char buf[4096];
    
    if(argc<3){
        printf("zbyt malo argumentow\n");
        exit(1);
    }
    
    fileToSave=open(argv[argc-1],O_CREAT | O_WRONLY | O_TRUNC, 0644);
    
    for(int i=1;i<argc-1;i++){
        fd=open(argv[i],O_RDONLY);
        while((n=read(fd,buf,4096))>0)
            write(fileToSave,buf,n);
        close(fd);
    }
    
    close(fileToSave);
    
    return 0;
}
