#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
    if(fork()==0){
        printf("child PID: %d\n",getpid());
        printf("child PPID: %d\n",getppid());
    }
    else{
        printf("parent PID: %d\n",getpid());
        printf("parent PPID: %d\n",getppid());
    }
    
    printf("HI\n");
    fork();
    printf("Ho\n");
    fork();
    printf("Ha\n");
    
    return 0;
}
