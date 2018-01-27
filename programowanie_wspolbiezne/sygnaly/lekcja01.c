#include <stdio.h>
#include <signal.h>

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
    signal(SIGINT,obslugaSigInt);
    while(a){
        
    }
    
    return 0;
}
