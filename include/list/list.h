#ifndef LIST_H
#define LIST_H
#include "sys_common.h"

// 链表节点结构
struct Node {
    void* data;
    struct Node* next;
};

// 在链表的末尾插入新节点
void list_insert(struct Node** head, void* data);

// 创建链表，并设置回调函数
struct Node* list_create(VOID * data);

// 销毁链表
void list_destroy(struct Node* head);

// 遍历并执行回调函数
void* list_traverse(struct Node** current);

#endif  // LIST_H
