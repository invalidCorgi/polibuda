#include <sys/types.h>   
#include <sys/ipc.h> 
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

#define M_DANE 10
#define M_END 11
#define M_WYNIK 12

int id;

void obslugaSigInt(){
    msgctl(id,IPC_RMID,0);
    kill(getpid(),SIGKILL);
}

struct msgbuf{
    long mtype;
    int number;
} mymsg;

int main(int argc, char* argv[])
{
    int wynik=0;
    id = msgget(0x40,0600 | IPC_CREAT);
    signal(SIGINT,obslugaSigInt);
//     msgrcv(id,&mymsg,sizeof(int),M_DANE,0);
//     wynik+=mymsg.number;
//     msgrcv(id,&mymsg,sizeof(int),M_DANE,0);
//     wynik+=mymsg.number;
//     msgrcv(id,&mymsg,sizeof(int),M_END,0);
//     wynik+=mymsg.number;
//     mymsg.mtype = M_WYNIK;
//     mymsg.number=wynik;
//     msgsnd(id,&mymsg,sizeof(int),0);
    while(1){
        if(msgrcv(id,&mymsg,sizeof(int),M_END,0)!=-1){
            wynik+=mymsg.number;
            while(msgrcv(id,&mymsg,sizeof(int),M_DANE,IPC_NOWAIT)!=-1)
                wynik+=mymsg.number;
            mymsg.mtype = M_WYNIK;
            mymsg.number=wynik;
            msgsnd(id,&mymsg,sizeof(int),0);
            wynik=0;
        }
    }
    
    return 0;
}
