#include <sys/types.h>   
#include <sys/ipc.h> 
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define M_DANE 10
#define M_END 11
#define M_WYNIK 12

struct msgbuf{
    long mtype;
    int number;
} mymsg;

int main(int argc, char* argv[])
{
    int id;
    id = msgget(0x40,0600);
    if(id==-1){
        puts("Serwer jest wylaczony, sprobuj ponownie pozniej");
        exit(0);
    }
    mymsg.mtype = M_DANE;
    mymsg.number = 10;
    msgsnd(id,&mymsg,sizeof(int),0);
    mymsg.number = 11;
    msgsnd(id,&mymsg,sizeof(int),0);
    mymsg.mtype = M_END;
    mymsg.number = 12;
    msgsnd(id,&mymsg,sizeof(int),0);
    msgrcv(id,&mymsg,sizeof(int),M_WYNIK,0);
    printf("%d\n",mymsg.number);
    
    return 0;
}
