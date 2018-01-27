#include <sys/types.h>   
#include <sys/ipc.h> 
#include <sys/msg.h>
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
    msgrcv(id,&mymsg,1024,40,0);
    msgctl(id,IPC_RMID,NULL);
    printf("%s",&(mymsg.text));
    
    return 0;
}
