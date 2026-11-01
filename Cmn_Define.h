/**
 * @file Cmn_Define.h
 * @author RuiCong
 * @brief 提供通用状态码及既有名称的兼容定义。
 * @date 2025-06-01
 *
 * @copyright Copyright (c) 2025 RuiCong. All rights reserved.
 */

#ifndef CMN_DEFINE_H_
#define CMN_DEFINE_H_


/*
****************************************************************************************************
*                                            头文件包含
****************************************************************************************************
*/

#include <stddef.h>


/*
****************************************************************************************************
*                                            公开宏定义
****************************************************************************************************
*/

/* 状态码 */

/*
 * 状态码：0 表示成功，其余值表示失败或异常，数值保持原有约定。
 * 新接口直接返回以下状态码，不隐式取负；旧接口保留并注明自身约定。
 * 此类返回值不是 xbool，调用方应显式比较 D_CMN_OK 或具体错误码。
 */
#define D_CMN_OK      (0)  /**< 成功。 */
#define D_CMN_ERROR   (1)  /**< 通用或未知错误。 */
#define D_CMN_TIMEOUT (2)  /**< 操作超时。 */
#define D_CMN_FULL    (3)  /**< 资源已满。 */
#define D_CMN_EMPTY   (4)  /**< 资源为空。 */
#define D_CMN_NOMEM   (5)  /**< 内存不足。 */
#define D_CMN_NOSYS   (6)  /**< 功能未实现。 */
#define D_CMN_BUSY    (7)  /**< 资源忙。 */
#define D_CMN_IO      (8)  /**< 输入输出错误。 */
#define D_CMN_INTR    (9)  /**< 操作被中断。 */
#define D_CMN_INVAL   (10) /**< 参数无效。 */
#define D_CMN_NOENT   (11) /**< 指定对象或条目不存在。 */
#define D_CMN_NOSPC   (12) /**< 可用空间不足。 */
#define D_CMN_PERM    (13) /**< 操作不被允许。 */
#define D_CMN_TRAP    (14) /**< 陷阱事件。 */

/* 旧名称兼容别名 */

/*
 * 仅为兼容既有代码保留，新代码使用 D_CMN_... 和标准 NULL。
 * XNULL 保留原来的 C/C++ 表示，避免改变已有调用点的类型行为。
 */
#if defined(__cplusplus)
#define XNULL (0)
#else
#define XNULL ((void *)0)
#endif

#define D_OK      D_CMN_OK
#define D_ERROR   D_CMN_ERROR
#define D_TIMEOUT D_CMN_TIMEOUT
#define D_FULL    D_CMN_FULL
#define D_EMPTY   D_CMN_EMPTY
#define D_NOMEM   D_CMN_NOMEM
#define D_NOSYS   D_CMN_NOSYS
#define D_BUSY    D_CMN_BUSY
#define D_IO      D_CMN_IO
#define D_INTR    D_CMN_INTR
#define D_INVAL   D_CMN_INVAL
#define D_NOENT   D_CMN_NOENT
#define D_NOSPC   D_CMN_NOSPC
#define D_PERM    D_CMN_PERM
#define D_TRAP    D_CMN_TRAP

#endif /* CMN_DEFINE_H_ */
