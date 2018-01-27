#include <sys/types.h>   
#include <sys/ipc.h> 
#include <sys/msg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct msgbuf{
    long mtype;
    char text[1024];
} mymsg;

int main(int argc, char* argv[])
{
    int id;
    id = msgget(0x40,0600 | IPC_CREAT);
    msgrcv(id,&mymsg,1024,69,0);
    //msgctl(id,IPC_RMID,NULL);
    for(int i=0;i<strlen(mymsg.text);i++)
    {
        if(mymsg.text[i]>='a' && mymsg.text[i]<='z')
            mymsg.text[i]-=0x20;
    }
//     printf("%s",mymsg.text);
    mymsg.mtype = 70;
    msgsnd(id,&mymsg,strlen(mymsg.text)+1,0);
    
    return 0;
}
