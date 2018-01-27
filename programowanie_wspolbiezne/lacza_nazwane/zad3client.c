#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <wait.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if(argc!=2){
        printf("potrzebny argument za pomoca jakiego lacza mamy sie komunikowac\n");
        exit(1);
    }
//     char str[] = "moje";
    char *str = argv[1];
    printf("wykorzystuje lacze zwrotne o nazwie %s\n",str);
    mkfifo(str,0600);
    char buf[4096];
    int n;
    int fd = open("kulawy",O_WRONLY);
    write(fd,str,strlen(str)+1);
    close(fd);
    fd = open(str,O_RDONLY);
    printf("odpowiedz serwera:\n");
    while((n=read(fd,buf,4096))>0){
        write(1,buf,n);
    }
    close(fd);
    
    unlink(str);
    return 0;
}
