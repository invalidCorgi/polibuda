#include <stdio.h>
#include <signal.h>
#include <string.h>

volatile int a=2;

void obslugaSigInt(){
    if(a==2)
        printf("\njescze nie wyjde\n");
    else
        printf("\nno dobra, wychodze\n");
    a--;
}

int main(int argc, char* argv[])
{
    struct sigaction si;
    memset(&si, 0, sizeof(sigaction));
    si.sa_sigaction = obslugaSigInt;
    
    sigaction(SIGINT, &si, NULL);
    while(a){
        
    }
    
    return 0;
}
