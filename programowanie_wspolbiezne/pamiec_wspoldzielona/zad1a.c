#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <string.h>
#include <stdio.h>
#include <sys/types.h>   
#include <unistd.h>

int main(int argc, char* argv[])
{
    int id;
    char* ha = "haaaa";
    char* ho = "hoooooo";
    char* wsk;
    
    id = shmget(666, 1024, 0644 | IPC_CREAT);
    wsk = (char*)shmat(id,NULL,SHM_RND);
    
    if(fork()){
        while(1){
            strcpy(wsk, ha);
            strcpy(wsk, ho);
        }
    }
    else{
        while(1){
            /*if(strcmp(wsk,ha))
                printf("to nie ha\n");
            else
                printf("mamy ha\n");
            if(strcmp(wsk,ho))
                printf("to nie ho\n");
            else
                printf("mamy ho\n");*/
            printf("%s\n",wsk);
        }
    }
            
            
    return 0;
}
