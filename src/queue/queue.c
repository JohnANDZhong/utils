#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <mqueue.h>
#include "queue.h"

/**
 * @brief 消息队列的初始化
 * 
 * @param id 消息队列的ID
 * @param maxNum 队列最大长度 
 * @param byteSize 队列的包长
 * @return INT32 创建成功还是失败  
 */


MSG_Q sys_queue_create(MSG_Q md, char *name, UINT32 maxNum, UINT32 byteSize)
{
    mqd_t md;
    struct mq_attr *msg;
   // msg->mq_flags = 0;
    msg->mq_maxmsg = maxNum;
    msg->mq_msgsize = byteSize;
   // msg->mq_curmsgs = id
    md = mq_open(name,O_RDWR|O_CREAT,0600,msg);   //open the queue to both send and receive message &没有就创建
    if(md < 0)
    {
        perror("mq_open()");
        return -1;
    }
    return md;
}

//消息队列的发送
/**
 * @brief 消息队列的发送
 * 
 * @param id 
 * @param data 发送数据指针
 * @param byteSize 数据大小
 * @param iWaitTime 延时多久发送 ms
 * @return INT32 发送成功还是失败
 */
INT32 sys_queue_send(MSG_Q md, char *data, UINT32 byteSize, UINT32 iWaitTime)
{
    if(mq_send(md,data,byteSize,0) < 0)
    {
        perror("mqsend()");
        mq_close(md);
        return -1;
    }
     pthread_create(pd,NULL,sys_queue_recv,0);
}

/**
 * @brief 消息队列的接收
 * 
 * @param id 
 * @param data 接受数据的指针
 * @param byteSize 接受数据的大小
 * @return INT32 发送成功还是失败
 */
INT32 sys_queue_recv(MSG_Q md, char *data, UINT32 byteSize)
{
    struct sigevent *notification;
    pthread_t pd;

   
    mq_notify(md,notification);
    if(mq_receive(md,data,byteSize,0) < 0)
    {
        perror("mq_recerive()");
        return -1;
    }
}

//消息队列的销毁
/**
 * @brief 
 * 
 * @param id 
 * @return INT32 
 */
INT32 sys_queue_del(MSG_Q md);
{

    mq_close();
    mq_unlink()
 
    pthread_cancel();
    pthread_join();
    return 0;
}
