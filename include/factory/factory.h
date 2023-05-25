/**
 * @file factory.h
 * @author JohnnyWong (1426384536@qq.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef __FACTORY_H__
#define __FACTORY_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sys_common.h"

// 单例对象结构
typedef struct {
    char* name;
    void* pData;
} Singleton;

/**
 * @brief 
 * 
 */
typedef struct {
    /**
     * @brief 
     * 
     */
    INT32 (*Init)(VOID);

    /**
     * @brief 
     * 
     */
    INT32 (*RegisterFactory)(char *IID, VOID *pFactory);
} Factory;


/**
 * @brief 
 * 
 * @return INT32 
 */
INT32 init_factory_compont(VOID);

/**
 * @brief 
 * 
 * @return Factory* 
 */
Factory *FACTORY_GET_COMPONT(VOID);


#endif