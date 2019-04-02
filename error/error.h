/**
  * @file       error.h
  * @brief      error头文件
  * @author     redoc <619675912@qq.com>
  * @version    v1.0
  * @date       2018-07-23
  *
  * @note
  * [2018-07-23] <redoc> v1.0
  * 初始版本
  *
  * @remark
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __ERROR_H
#define __ERROR_H

/* Includes ------------------------------------------------------------------*/
#include "stdint.h"
#include "stdio.h"
#include "error_define.h"

/* types ------------------------------------------------------------*/

/* 错误结构体 */
typedef union
{
    uint16_t value;
    
    struct 
    {
        uint8_t     level       :  2;       /*<!  错误等级,暂时未做处理   */
        uint8_t     exist       :  1;       /*<!  节点存在标志            */
        uint8_t     used        :  1;       /*<!  节点是否被处理          */
        uint16_t    id          : 10;       /*<!  错误代码  最大1024个    */
        uint8_t     reserveed   :  2;       /*<!  预留                    */
    }var;
    
}error_t;


/* 错误链表结构体 */
typedef struct error_node_t
{
    error_t error;                        /*<!  错误                    */
    struct error_node_t *next;            /*<!  指向下一个节点的指针    */
    
}error_node_t;

/* define -----------------------------------------------------------*/
/*   error pintf debug   */
//#define ERRROR_PRINT

/* variables --------------------------------------------------------*/


/* macro ------------------------------------------------------------*/
/* functions --------------------------------------------------------*/
int8_t error_exist(error_node_t *s_error_code);
int8_t error_insert(error_node_t *s_error_code);
int8_t error_delete(error_node_t *s_error_code);
void error_process(void);

#endif
