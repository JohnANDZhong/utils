#include "factory.h"
#include "list.h"
#include "stdlib.h"

static LIST_NODE *gFactoryList = NULL;


INT32 init_factory_component()
{
    // Implementation of init_factory_component()
    // TODO: Add your code here
    gFactoryList = list_create(NULL);
    SYS_CHECK_PTR_RET(gFactoryList, ERROR);
    return OK; // or any appropriate return value
}

INT32 register_factory_component(const UINT8 *IID, VOID *pFactory)
{
    INT32 iRet = ERROR;
    Singleton *pNode = NULL;
    pNode = (Singleton*)malloc(sizeof(Singleton));
    SYS_CHECK_PTR_RET(pNode, ERROR);

    pNode->pData = pFactory;
    strncpy(pNode->name, IID, strlen(IID));

    iRet = list_insert(&gFactoryList, pNode);
    if(iRet != OK)
    {
        LOG_MESSAGE(LOG_ERROR, "Register factory component failed!");
        free(pNode);
        return ERROR;
    }

    LOG_MESSAGE(LOG_INFO, "Register factory component %s success!", IID);
    return OK;
}

VOID *get_factory_component(const UINT8 *IID)
{
    LIST_NODE *pNode = gFactoryList;
    Singleton *pFactory = NULL;

    pFactory = list_traverse(&pNode);

    return pFactory;
}
