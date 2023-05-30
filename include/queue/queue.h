#ifndef QUEUE_H__
#define QUEUE_H__
#define   KEYPATH   "/etc/services/"
#define   KEYPROJ   'w'

typedef struct snd_st   //发送内容
{
    void *snd_ct(void );

}snd_cntext;

struct msg_st       //消息队列
{
    long mtype;
    snd_cntext *snd;
};
extern struct msg_st *msgp; 
key_t getid(void);
int msg_create(key_t,struct msg_st* );
int msg_destory(int);
void *snd_ct(void);
#endif