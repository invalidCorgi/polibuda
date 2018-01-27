#include <sys/types.h>   
#include <sys/ipc.h> 
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct msgbuf{
    long mtype;
    char text[1024];
} mymsg;

int main(int argc, char* argv[])
{
    int id;
    id = msgget(0x40,0600 | IPC_CREAT);
    strcpy(mymsg.text,"kulawy\n");
    mymsg.mtype = 69;
    msgsnd(id,&mymsg,strlen(mymsg.text)+1,0);
    msgrcv(id,&mymsg,1024,70,0);
    printf("%s",mymsg.text);
    
    return 0;
}
