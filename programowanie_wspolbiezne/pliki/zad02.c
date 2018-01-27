#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
    //printf("%s",argv[1]);
    int fd1, fd2, n, index=0;
    char ar_buf[100],buf ;

    fd1 = open(argv[1], O_RDONLY);
    fd2 = open(argv[2], O_CREAT | O_RDWR | O_TRUNC , 0644);

    while((n=read(fd1,&buf,1)) > 0)
    {
        if(buf != '\n'){
            ar_buf[index++]=buf;
        }
        else{
            ar_buf[index]='\n';
            int index2 = index;
            for(int i=0; i<index2; i++, index2--){
                buf=ar_buf[i];
                ar_buf[i]=ar_buf[index2];
                ar_buf[index2]=buf;
            }
            write(fd2,ar_buf,index+1);
            index=0;
        }
    }

    close(fd1);
    close(fd2);
    return 0;
}
