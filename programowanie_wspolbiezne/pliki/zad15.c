#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
    int n1,n2,n3, fd1, fd2,col=1,row=1;
    char buf1[4096], buf2[4096];
    
    if(argc!=3){
        printf("zla liczba argumentow\n");
        exit(1);
    }
    
    fd1=open(argv[1],O_RDONLY);
    fd2=open(argv[2],O_RDONLY);
    
    while(1){
        n1=read(fd1,buf1,4096);
        n2=read(fd2,buf2,4096);
        
        if(n1==0 && n2==0){
            printf("pliki sa identyczne\n");
            close(fd1);close(fd2);
            exit(1);
        }
        
        if(n1>n2)n3=n2;else n3=n1;
        
        for(int i=0;i<n3;i++){
            if(buf1[i]!=buf2[i]){
                printf("pliki roznia sie od znaku nr %d w linii nr %d\n",col,row);
                close(fd1);close(fd2);
                exit(1);
            }
            else{
                if(buf1[i]=='\n'){
                    row++;
                    col=1;
                }
                else
                    col++;
            }
        }
        
        if(n1>n2){
            int bonus = n1-n2;
            while((n3=read(fd1,buf1,4096))>0)
                bonus+=n3;
            printf("plik %s zawiera %d znakow wiecej niz zawartosc pliku %s\n",argv[1],bonus,argv[2]);
            close(fd1);close(fd2);
            exit(1);
        }
        if(n2>n1){
            int bonus = n2-n1;
            while((n3=read(fd2,buf2,4096))>0)
                bonus+=n3;
            printf("plik %s zawiera %d znakow wiecej niz zawartosc pliku %s\n",argv[2],bonus,argv[1]);
            close(fd1);close(fd2);
            exit(1);
        }
    }
    
    return 0;
}
