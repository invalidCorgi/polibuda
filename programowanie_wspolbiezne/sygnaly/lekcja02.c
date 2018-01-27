#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void obslugaSigInt(){
    printf("Zabijam ojca, pieprzonego morderce i popelniam samobojstwo");
    kill(getppid(),SIGINT);
    exit(0);
}

int main(int argc, char* argv[])
{
    int childPID;
    
    if((childPID=fork())==0){
        signal(SIGINT,obslugaSigInt);
        while(1);
    }
    
    sleep(5);
    kill(childPID,SIGINT);
    sleep(5);
    
    return 0;
}
