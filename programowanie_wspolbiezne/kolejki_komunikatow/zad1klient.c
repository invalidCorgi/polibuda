#include <sys/types.h>   
#include <sys/ipc.h> 
#include <sys/msg.h>
#include <string.h>

struct msgbuf{
    long mtype;
    char text[1024];
} mymsg;

int main(int argc, char* argv[])
{
    int id;
    id = msgget(0x40,0600 | IPC_CREAT);
    strcpy(mymsg.text,"kulawy\n");
    mymsg.mtype = 40;
    msgsnd(id,&mymsg,strlen(mymsg.text)+1,0);
    
    return 0;
}
