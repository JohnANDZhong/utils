#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
//#include <mqueue.h>
#include "sys_logger.h"
//#include "sys_common.h"
#include "queue.h"

/**
 * @brief 消息队列的初始化
 * 
 * @param id 消息队列的ID
 * @param maxNum 队列最大长度 
 * @param byteSize 队列的包长
 * @return INT32 创建成功还是失败  
 */


INT32 sys_queue_create(MSG_Q *id, char *name, UINT32 maxNum, UINT32 byteSize)
{
   // mqd_t md;
    struct mq_attr msg;
  
  /* if(id == NULL || name == NULL)
    {
        LOG_MESSAGE(LOG_ERROR, "name or id is null");
        return ERROR;
    }*/
    msg.mq_flags = 0;
    msg.mq_maxmsg = maxNum;
    msg.mq_msgsize = byteSize;
    msg.mq_curmsgs = 0;
    *id = mq_open(name, O_RDWR|O_CREAT, 0666, &msg);   //open the queue to both send and receive message &没有就创建
    if(0 > *id)
    {
        perror("mq_open()");
        LOG_MESSAGE(LOG_ERROR, "mq_open fail");
        return ERROR;
    }
    
   // *id = md;

    return OK;
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
INT32 sys_queue_send(MSG_Q *id, void *data, UINT32 byteSize, UINT32 iWaitTime)
{
    INT32 ret = ERROR;
    INT32 pri = 1;
    if(id == NULL)
    {
        LOG_MESSAGE(LOG_ERROR, "id null");
        return ERROR;
    }

    usleep(1000*iWaitTime);

    ret = mq_send(*id, (char *)data, byteSize, pri);
    if(0 > ret)
    {
        LOG_MESSAGE(LOG_ERROR, "mq_semd()fail");
        return ERROR;
    }
   return OK;
}

/**
 * @brief 消息队列的接收
 * 
 * @param id 
 * @param data 接受数据的指针
 * @param byteSize 接受数据的大小
 * @return INT32 发送成功还是失败
 */

INT32 sys_queue_recv(MSG_Q *id, void *data, UINT32 byteSize)
{
    ssize_t len;
    INT32 pri;
    len = mq_receive(*id, (char *)data, (size_t)byteSize, &pri);
    if(0 > len)
    {
        LOG_MESSAGE(LOG_ERROR, "mq_receive()fail");
        return ERROR;
    }

    return OK;
}

//消息队列的销毁
/**
 * @brief 
 * 
 * @param id 
 * @return INT32 
 */
INT32 sys_queue_del(MSG_Q *id, char *name)
{

    mq_close(*id);
    mq_unlink(name);
    return OK;
}
