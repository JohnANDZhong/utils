#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "queue.h"
void *snd_ct(void)
{
    char *s = "sending";
    printf("%s\n",s);
    return s;
}
key_t getid(void)
{
    key_t key;
    key = ftok(KEYPATH,KEYPROJ);
    if(key < 0)
    {
        perror("ftok()");
        exit(1);
    }
    return key;
}
int msg_create(key_t key,struct msg_st* msgp)
{
    int id;
    struct msg_st *sndp = msgp;
     id = msgget(key,IPC_CREAT|0600) ;
     if(id < 0)
     {
        perror("msgget()");
        return -1;
     }
    if(msgsnd(id,sndp->snd->snd_ct,sizeof(struct msg_st)-sizeof(long),0) < 0)
    {
        perror("msgsnd()");
        return -2;
    }
    puts("ok");
    return id;
}
int msg_destory(int msqid)
{
    int id = msqid;
    msgctl(id,IPC_RMID,NULL);
    return 0;
}



