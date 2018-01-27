#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <wait.h>

int main(int argc, char* argv[])
{
    mkfifo("tr",0644);
    mkfifo("cut",0644);
    mkfifo("sort1",0644);
    mkfifo("uniq",0644);
    mkfifo("sort2",0644);
    
    if(fork()!=0)
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
    }
    
    if(fork()!=0)
    {
        int fd1 = open("tr",O_RDONLY);
        int fd2 = open("cut",O_WRONLY);
        dup2(fd1,0);
        dup2(fd2,1);
        execl("/bin/tr","tr","-s","' '",":",NULL);
        close(fd1);
        close(fd2);
        exit(1);
    }
    
    int fd = open("tr",O_WRONLY);
    dup2(fd,1);
    execl("/bin/ps","ps","-ef",NULL);
    close(fd);
    
    return 0;
}
