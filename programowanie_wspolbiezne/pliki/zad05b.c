#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
    int fd1,i=0,j;
    char temp, line[1024];
    
    fd1 = open(argv[1], O_RDONLY);
    lseek(fd1, -1, SEEK_END);
    read(fd1,&temp,1);
    if(temp=='\n')
        write(0,&temp,1);
    else
        line[i++]=temp;
    
    while(lseek(fd1,-2,SEEK_CUR)){
        read(fd1,&temp,1);
        if(temp!='\n')
            line[i++]=temp;
        else{
            line[i]='\n';
            j=i-1;
            for(int k=0; k<j; k++, j--){
                temp=line[k];
                line[k]=line[j];
                line[j]=temp;
            }
            write(0,line,i+1);
            i=0;
        }
    }
    
    read(fd1,&temp,1);
    line[i]=temp;
    j=i;
    for(int k=0; k<j; k++, j--){
        temp=line[k];
        line[k]=line[j];
        line[j]=temp;
    }
    write(0,line,i+1);
    puts("");
    
    return 0;
}
