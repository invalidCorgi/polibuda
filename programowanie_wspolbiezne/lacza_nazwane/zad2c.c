#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <wait.h>

int main(int argc, char* argv[])
{
    mkfifo("kulawy1",0600);
    mkfifo("kulawy2",0600);
    //dup2(1,5);
    int fd1 = open("kulawy1",O_NDELAY);
    dup2(fd1,1);
    execl("/bin/ps","ps","-ef",NULL);
    
    if(fork()==0)
    {
        int fd1 = open("kulawy1",O_RDONLY);
//         int fd2 = open("kulawy2",O_WRONLY);
        dup2(fd1,0);
        dup2(5,1);
//         dup2(fd2,1);
        execl("/bin/tr","tr","-s","' '",":",NULL);
        close(fd1);
//         close(fd2);
        exit(1);
    }
    
    close(fd1);
    unlink("kulawy1");
    unlink("kulawy2");
    
    /*if(fork()==0)
    {
        int fd1 = open("sort2",O_RDONLY);
        dup2(fd1,0);
        execl("/bin/sort","sort","-nr",NULL);
        close(fd1);
        exit(1);
    }
    
    if(fork()!=0)
    {
        int fd1 = open("uniq",O_RDONLY);
        int fd2 = open("sort2",O_WRONLY);
        dup2(fd1,0);
        dup2(fd2,1);
        execl("/bin/uniq","uniq","-c",NULL);
        close(fd1);
        close(fd2);
        exit(1);
    }
    
    if(fork()!=0)
    {
        int fd1 = open("sort1",O_RDONLY);
        int fd2 = open("uniq",O_WRONLY);
        dup2(fd1,0);
        dup2(fd2,1);
        execl("/bin/sort","sort",NULL);
        close(fd1);
        close(fd2);
        exit(1);
    }
    
    if(fork()!=0)
    {
        int fd1 = open("cut",O_RDONLY);
        int fd2 = open("sort1",O_WRONLY);
        dup2(fd1,0);
        dup2(fd2,1);
        execl("/bin/cut","cut","-d:","-f1",NULL);
        close(fd1);
        close(fd2);
        exit(1);
    }*/
    
    
    
    
    return 0;
}
