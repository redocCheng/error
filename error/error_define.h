/**
  * @file       error_define.h
  * @brief      error_define头文件
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


/* types ------------------------------------------------------------*/

/* 错误代码ID */
typedef enum
{
    ERROR_ID_ERROR_1 = 0x01,                         
    ERROR_ID_ERROR_2,                           
    ERROR_ID_ERROR_3, 

}error_id_t;


/* variables --------------------------------------------------------*/
extern error_node_t error_node_error_1;
extern error_node_t error_node_error_2;
extern error_node_t error_node_error_3;



#endif