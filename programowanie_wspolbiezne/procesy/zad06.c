#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    int fd = open(argv[1], O_CREAT | O_TRUNC | O_RDWR, 0644);
    
    for(int j=0;j<100;j++){
        for(int i=0;i<26;i++){
            if(fork()==0){
                char c = i+65;
                write(fd,&c,1);
                exit(0);
            }
        }
        for(int i=0;i<26;i++){
            wait(NULL);
        }
        char c='\n';
        write(fd,&c,1);
    }
    
    puts("Koniec");
    
    return 0;
}
