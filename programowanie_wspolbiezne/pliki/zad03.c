#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
    int fd1, fd2, n, index=0, longest_length=0;
    char ar_buf[1000], buf, longest_line[1000];

    fd1 = open(argv[1], O_RDONLY);
    //fd2 = open(argv[2], O_RDWR | O_TRUNC , 0644);

    while((n=read(fd1,&buf,1)) > 0)
    {
        if(buf != '\n'){
            ar_buf[index++]=buf;
        }
        else{
            ar_buf[index]='\n';
            if(index>longest_length){
                longest_length=index;
                for(int i=0; i<=index; i++){
                    longest_line[i]=ar_buf[i];
                }
            }
            index=0;
        }
    }
    
    close(fd1);
    close(fd2);
    
    printf("Longest line: \n");
    puts(longest_line);
    printf("Contains %d characters",longest_length);
    
    return 0;
}
