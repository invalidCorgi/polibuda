#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    printf("Poczatek\n");
    if(fork()!=0)
        wait(NULL);
    else{
        execl("/bin/ls","ls","-a",NULL);
        exit(1);
    }
    printf("Koniec\n");
    
    return 0;
}
