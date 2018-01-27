#include <sys/types.h>   
#include <sys/ipc.h> 
#include <sys/sem.h>
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char* argv[])
{
    int semafor_id = semget(1357,6,IPC_CREAT|IPC_EXCL|0644);
    if(semafor_id==-1){
        semafor_id = semget(1357,6,IPC_CREAT|0644);
    }
    short tab[6] = {1,1,1,1,1,4};
    int pid[5];
    semctl(semafor_id,0,SETALL,tab);
    
    for(int i=0;i<5;i++){
        if((pid[i]=fork())==0){
            semafor_id = semget(1357,6,IPC_CREAT|0644);
            while(1){}
        }
    }
    
    sleep(10);
    for(int i=0;i<5;i++)
        kill(pid[i],SIGKILL);
    
    return 0;
}
