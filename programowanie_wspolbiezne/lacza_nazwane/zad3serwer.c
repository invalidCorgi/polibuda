#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <wait.h>

char *str;

void obslugaSigInt(){
    printf("odebrano zadanie wylaczenia serwera, usuwam lacze dla klientow: %s\n",str);
    unlink(str);
    exit(0);
}

int main(int argc, char* argv[])
{
    if(argc!=2){
        printf("potrzebny argument za pomoca jakiego lacza mamy sie komunikowac\n");
        exit(1);
    }
    str = argv[1];
    mkfifo(str,0600);
    printf("stworzono lacze dla klientow o nazwie %s\n",str);
    signal(SIGINT,obslugaSigInt);
    while(1)
    {
    char buf[4096];
    int n;
    int fd = open(str,O_RDONLY);
    while((n=read(fd,buf,4096))>0);
    close(fd);
    printf("odeslano kulawego\n",buf);
    fd = open(buf,O_WRONLY);
    write(fd,"kulawy\n",8);
    close(fd);
    }
    
    return 0;
}
