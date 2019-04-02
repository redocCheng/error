/**
  * @file        error.c
  * @brief        error定义
  * @author     redoc
  * @version    v1.0
  * @date        2018-07-23
  *
  * @note
  * [2018-07-23] <redoc> (v1.0) 
  * 初始版本
  *
  * @remark
  */

/* Includes ------------------------------------------------------------------*/
#include "error.h"


error_node_t error_node_error_1 = 
{
    .error.var.level    =    0,
    .error.var.id       =    ERROR_ID_ERROR_1,
    .next               =    NULL,
};

error_node_t error_node_error_2 = 
{
    .error.var.level    =    0,
    .error.var.id       =    ERROR_ID_ERROR_2,
    .next               =    NULL,
};

error_node_t error_node_error_3 = 
{
    .error.var.level    =    0,
    .error.var.id       =    ERROR_ID_ERROR_3,
    .next               =    NULL,
};



