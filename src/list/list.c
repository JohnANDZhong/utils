#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// 在链表的末尾插入新节点
INT32 list_insert(struct Node** head, void* data) {
    // 创建新节点
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // 如果链表为空，将新节点设置为头节点
    if (*head == NULL) {
        *head = newNode;
        return ERROR;
    }

    // 找到链表的末尾节点
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    // 将新节点链接到末尾节点
    current->next = newNode;
    return OK;
}

// 创建链表，并设置回调函数
struct Node* list_create(VOID *pData) {
    struct Node* head = NULL;
    list_insert(&head, pData);
    return head;
}

// 销毁链表
void list_destroy(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

// 遍历并执行链表节点的回调函数，返回当前节点的内容
void* list_traverse(struct Node** current) {
    if (*current == NULL) {
        return NULL;
    }

    struct Node* currentNode = *current;
    *current = (*current)->next;
    return currentNode->data;
}
