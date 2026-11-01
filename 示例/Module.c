/**
 * @file Module.c
 * @author <实际作者或团队>
 * @brief 实现阈值配置校验、保存和状态查询。
 * @date <创建日期：YYYY-MM-DD>
 *
 * @copyright <按实际归属填写>
 */


/*
****************************************************************************************************
*                                            头文件包含
****************************************************************************************************
*/

#include "Module.h"

#include <stddef.h>


/*
****************************************************************************************************
*                                             私有变量
****************************************************************************************************
*/

/* 配置复制到模块内部，避免调用方配置对象的生命周期影响后续读取。 */
static Module_Config_s Config = {0U};
static xbool IsReady = xfalse;


/*
****************************************************************************************************
*                                           私有函数声明
****************************************************************************************************
*/

static xbool module_IsConfigValid(const Module_Config_s *_cpConfig);


/*
****************************************************************************************************
*                                             私有函数
****************************************************************************************************
*/

/**
 * @brief 检查配置指针和阈值范围，不修改模块状态。
 */
static xbool module_IsConfigValid(const Module_Config_s *_cpConfig)
{
    if (_cpConfig == NULL)
    {
        return xfalse;
    }

    if (_cpConfig->sLimitMv == 0U)
    {
        return xfalse;
    }

    return xtrue;
}


/*
****************************************************************************************************
*                                             公开函数
****************************************************************************************************
*/

xbool Module_Init(const Module_Config_s *_cpConfig)
{
    /* 先完成所有校验，再更新状态，使失败调用保留上一次有效配置。 */
    if (module_IsConfigValid(_cpConfig) == xfalse)
    {
        return xfalse;
    }

    Config = *_cpConfig;
    IsReady = xtrue;

    return xtrue;
}

xbool Module_IsReady(void)
{
    return IsReady;
}

xbool Module_GetLimitMv(xint16u *_pLimitMv)
{
    if (_pLimitMv == NULL)
    {
        return xfalse;
    }

    if (IsReady == xfalse)
    {
        return xfalse;
    }

    *_pLimitMv = Config.sLimitMv;

    return xtrue;
}
