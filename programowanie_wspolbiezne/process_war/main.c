#include <sys/ipc.h> 
#include <sys/sem.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <unistd.h> 
#include <stdio.h>
#include <sys/wait.h>

static struct sembuf buf;

void P(int semid){
    buf.sem_op = -1;
    semop(semid, &buf, 1);
}

void V(int semid){
    buf.sem_op = 1;
    semop(semid, &buf, 1);
}

int main(int argc, char* argv[])
{
    buf.sem_num = 0;
    buf.sem_flg = 0;
    
    int no_proc;
    
    if(argc==2){
        no_proc = atoi(argv[1]);
        if(no_proc < 1)
            no_proc = 10;
    }
    else
        no_proc = 1;
    
    int i, semid,status,pids[no_proc];
    
    semid = semget(23,1,IPC_CREAT|0600);
    semctl(semid,0,SETVAL,1);
    
    for(i=0; i<no_proc; i++)
        if(fork()==0){
            P(semid);
            printf("Process %d captured the flag!!!\n",i);
            printf("Process %d died\n",i);
            V(semid);
            exit(i);
        }
    
    for(i=0;i<no_proc;i++){
        wait(&status);
        status >>= 8;
        if(i == no_proc - 1)
            printf("\n!!! Process %d died but won the process war !!!\n\n",status);
    }
    semctl(semid,1,IPC_RMID,NULL);
    return 0;
}
